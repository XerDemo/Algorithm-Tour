import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MazeDFS {

    private static int blockSide = 8;             // 每个格子边框大小
    private static final int DELAY = 5;           // 线程休眠时间
    private MazeData data;                        // 数据
    private MazeFrame frame;                      // 视图
    private boolean isContinue = true;            // 是否继续探测  true:是
    public static final int[][] direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  //  探测方向 依次从 左  下  右  上 四个方向探测 逆时针

    public MazeDFS(String mazeFile) {

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
        // 如果没有找到出口  会执行里面的go()
        if (!go(data.getEntranceX(), data.getEntranceY())) {
            System.out.println("maze is no solve.");
        }
    }

    // 从(x,y)的位置求解迷宫成功的话 返回true  DFS深度优先遍历
    private boolean go(int x, int y) {
        // 如果不在迷宫的范围
        if (!data.inArea(x, y))
            throw new IllegalArgumentException("x or y is out of index in Maze!");

        data.visited[x][y] = true;      // 将该点置为访问状态
        setData(x, y, true);      // 将该点加入到path[x][y] = true  表示绘制该点：黄色

        // 递归结束条件  当走到了出口 结束
        if (x == data.getExitX() && y == data.getExitY()) {
            return true;
        }

        // 试探方向
        for (int i = 0; i < 4; ++i) {
            // 新的坐标NewX NewY
            int newX = x + direction[i][0];
            int newY = y + direction[i][1];

            // Maze[newX][newY]此点  在迷宫范围内   &&  是路不是墙  &&  没有被访问过
            if (data.inArea(newX, newY) && data.getMaze(newX, newY) == MazeData.ROAD && !data.visited[newX][newY]) {
                if (go(newX, newY)) {
                    return true;
                }
            }
        }
        // 每个方向都试探了
        setData(x, y, false);  // 将之前加入path[x][y]置为false  (回溯)
        return false;
    }

    // 绘制 找到迷宫的线路
    private void setData(int x, int y, boolean isPath) {
    	// 如果在迷宫内
        if (data.inArea(x, y)) {
            data.path[x][y] = isPath;   
        }
        frame.render(data);
        MazeHelper.pause(DELAY);
    }


    public static void main(String[] args) {

        String mazeFile = "maze_101_101.txt";
        MazeDFS mazeDFS = new MazeDFS(mazeFile);
        mazeDFS.run();

    }
}