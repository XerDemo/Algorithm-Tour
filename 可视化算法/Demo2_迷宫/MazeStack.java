import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Stack;

public class MazeStack {

    private static int blockSide = 8;             // 每个格子边框大小
    private static final int DELAY = 3;           // 线程休眠时间
    private MazeData data;                        // 数据
    private MazeFrame frame;                      // 视图
    private boolean isContinue = true;            // 是否继续探测  true:是
    private boolean isSolve;                      // 是否找到路径
    public static final int[][] direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  //  探测方向 依次从 左  下  右  上 四个方向探测 逆时针

    public MazeStack(String mazeFile) {

        // 初始化数据
        data = new MazeData(mazeFile);
        int sceneWidth = data.M() * blockSide;      // Jpanel面板的宽
        int sceneHeight = data.N() * blockSide;     // Jpanel面板的高

        // 初始化视图
        // java8 引入的新方法 ()->   资料:https://blog.csdn.net/renfufei/article/details/24600507
        EventQueue.invokeLater(() -> {
            // 创建窗口
            frame = new MazeFrame("Welcome", sceneWidth, sceneHeight);
       
            // 在EventQueue.invokeLater 事件分发队列中再创建一个线程
            new Thread(() -> {
                run();
            }).start();
        });
    }

    // 编写动画效果
    private void run() {
        Stack<Position> stack = new Stack<Position>();                        // 创建栈

        stack.push(new Position(data.getEntranceX(), data.getEntranceY()));   // 将入口压入占中

        data.visited[data.getEntranceX()][data.getEntranceY()] = true;        // 将入口置为访问过

        // 如果栈不空
        while (!stack.empty()) {
            Position curPos = stack.pop();                                    // 出栈
            setData(curPos.getX(), curPos.getY(), true);                // 绘制 黄色

            // 当前点为出口
            if (curPos.getX() == data.getExitX() && curPos.getY() == data.getExitY()) {
                isSolve = true;                                                // 置为true 找到迷宫解：路径
                findPath(curPos);                                              // 从出口往回找路径
                break;
            }

            // 探测方向
            for (int i=0; i<4;++i) {
                // 新的坐标NewX NewY
                int newX = curPos.getX() + direction[i][0];
                int newY = curPos.getY() + direction[i][1];

                // Maze[newX][newY]此点  在迷宫范围内   &&  是路不是墙  &&  没有被访问过
                if (data.inArea(newX, newY) && data.getMaze(newX, newY) == MazeData.ROAD && !data.visited[newX][newY]) {
                    stack.push(new Position(newX, newY,curPos));              // 新点 进站
                    data.visited[newX][newY] = true;                          // 新点 置为 访问过
                }
            }
        }
        // 如果到最后 还没找到迷宫的解
        if (!isSolve) {
            System.out.println("maze is no solve.");
        }
    }

    // 从出口 往回找路径
    private void findPath(Position desc) {
        Position cur = desc;                                // 当前所在点
        while (cur != null) {                               // 不为空
            data.result[cur.getX()][cur.getY()] = true;     // result设为true
            cur = cur.getPreStackNode();                    // 继续往前找
        }
    }

    // 绘制 找到迷宫的线路
    private void setData(int x, int y, boolean isPath) {
        if (data.inArea(x, y)) {
            data.path[x][y] = isPath;
        }
        frame.render(data);
        MazeHelper.pause(DELAY);
    }


    public static void main(String[] args) {

        String mazeFile = "maze_101_101.txt";
        MazeStack mazeStack = new MazeStack(mazeFile);
        mazeStack.run();
    }
}