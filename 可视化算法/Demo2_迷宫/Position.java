/**
 *  ����ջ�������� �Թ�ʱ ��(x,y)����һ��ջ�ڵ�
 */
public class Position {
    private int x;
    private int y;
    private Position preStackNode;                          

    public Position(int x, int y) {
        this(x, y, null);
    }

    public Position(int x, int y, Position preStackNode) {
        this.x = x;
        this.y = y;
        this.preStackNode = preStackNode;
    }

    // ���û�ȡ��Ӧ��get����
    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Position getPreStackNode() {
        return preStackNode;
    }
}
