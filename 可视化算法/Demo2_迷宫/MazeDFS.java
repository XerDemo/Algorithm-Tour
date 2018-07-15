import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MazeDFS {

    private static int blockSide = 8;             // ÿ�����ӱ߿��С
    private static final int DELAY = 5;           // �߳�����ʱ��
    private MazeData data;                        // ����
    private MazeFrame frame;                      // ��ͼ
    private boolean isContinue = true;            // �Ƿ����̽��  true:��
    public static final int[][] direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  //  ̽�ⷽ�� ���δ� ��  ��  ��  �� �ĸ�����̽�� ��ʱ��

    public MazeDFS(String mazeFile) {

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
        // ���û���ҵ�����  ��ִ�������go()
        if (!go(data.getEntranceX(), data.getEntranceY())) {
            System.out.println("maze is no solve.");
        }
    }

    // ��(x,y)��λ������Թ��ɹ��Ļ� ����true  DFS������ȱ���
    private boolean go(int x, int y) {
        // ��������Թ��ķ�Χ
        if (!data.inArea(x, y))
            throw new IllegalArgumentException("x or y is out of index in Maze!");

        data.visited[x][y] = true;      // ���õ���Ϊ����״̬
        setData(x, y, true);      // ���õ���뵽path[x][y] = true  ��ʾ���Ƹõ㣺��ɫ

        // �ݹ��������  ���ߵ��˳��� ����
        if (x == data.getExitX() && y == data.getExitY()) {
            return true;
        }

        // ��̽����
        for (int i = 0; i < 4; ++i) {
            // �µ�����NewX NewY
            int newX = x + direction[i][0];
            int newY = y + direction[i][1];

            // Maze[newX][newY]�˵�  ���Թ���Χ��   &&  ��·����ǽ  &&  û�б����ʹ�
            if (data.inArea(newX, newY) && data.getMaze(newX, newY) == MazeData.ROAD && !data.visited[newX][newY]) {
                if (go(newX, newY)) {
                    return true;
                }
            }
        }
        // ÿ��������̽��
        setData(x, y, false);  // ��֮ǰ����path[x][y]��Ϊfalse  (����)
        return false;
    }

    // ���� �ҵ��Թ�����·
    private void setData(int x, int y, boolean isPath) {
    	// ������Թ���
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