/**
 *  在用栈方法遍历 迷宫时 将(x,y)看成一个栈节点
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

    // 设置获取相应的get方法
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
