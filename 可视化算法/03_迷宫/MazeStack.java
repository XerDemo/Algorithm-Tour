import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.Stack;

public class MazeStack {

    private static int blockSide = 8;             // ÿ�����ӱ߿��С
    private static final int DELAY = 3;           // �߳�����ʱ��
    private MazeData data;                        // ����
    private MazeFrame frame;                      // ��ͼ
    private boolean isContinue = true;            // �Ƿ����̽��  true:��
    private boolean isSolve;                      // �Ƿ��ҵ�·��
    public static final int[][] direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  //  ̽�ⷽ�� ���δ� ��  ��  ��  �� �ĸ�����̽�� ��ʱ��

    public MazeStack(String mazeFile) {

        // ��ʼ������
        data = new MazeData(mazeFile);
        int sceneWidth = data.M() * blockSide;      // Jpanel���Ŀ�
        int sceneHeight = data.N() * blockSide;     // Jpanel���ĸ�

        // ��ʼ����ͼ
        // java8 ������·��� ()->   ����:https://blog.csdn.net/renfufei/article/details/24600507
        EventQueue.invokeLater(() -> {
            // ��������
            frame = new MazeFrame("Welcome", sceneWidth, sceneHeight);
       
            // ��EventQueue.invokeLater �¼��ַ��������ٴ���һ���߳�
            new Thread(() -> {
                run();
            }).start();
        });
    }

    // ��д����Ч��
    private void run() {
        Stack<Position> stack = new Stack<Position>();                        // ����ջ

        stack.push(new Position(data.getEntranceX(), data.getEntranceY()));   // �����ѹ��ռ��

        data.visited[data.getEntranceX()][data.getEntranceY()] = true;        // �������Ϊ���ʹ�

        // ���ջ����
        while (!stack.empty()) {
            Position curPos = stack.pop();                                    // ��ջ
            setData(curPos.getX(), curPos.getY(), true);                // ���� ��ɫ

            // ��ǰ��Ϊ����
            if (curPos.getX() == data.getExitX() && curPos.getY() == data.getExitY()) {
                isSolve = true;                                                // ��Ϊtrue �ҵ��Թ��⣺·��
                findPath(curPos);                                              // �ӳ���������·��
                break;
            }

            // ̽�ⷽ��
            for (int i=0; i<4;++i) {
                // �µ�����NewX NewY
                int newX = curPos.getX() + direction[i][0];
                int newY = curPos.getY() + direction[i][1];

                // Maze[newX][newY]�˵�  ���Թ���Χ��   &&  ��·����ǽ  &&  û�б����ʹ�
                if (data.inArea(newX, newY) && data.getMaze(newX, newY) == MazeData.ROAD && !data.visited[newX][newY]) {
                    stack.push(new Position(newX, newY,curPos));              // �µ� ��վ
                    data.visited[newX][newY] = true;                          // �µ� ��Ϊ ���ʹ�
                }
            }
        }
        // �������� ��û�ҵ��Թ��Ľ�
        if (!isSolve) {
            System.out.println("maze is no solve.");
        }
    }

    // �ӳ��� ������·��
    private void findPath(Position desc) {
        Position cur = desc;                                // ��ǰ���ڵ�
        while (cur != null) {                               // ��Ϊ��
            data.result[cur.getX()][cur.getY()] = true;     // result��Ϊtrue
            cur = cur.getPreStackNode();                    // ������ǰ��
        }
    }

    // ���� �ҵ��Թ�����·
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