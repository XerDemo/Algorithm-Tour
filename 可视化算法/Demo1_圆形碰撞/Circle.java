import java.awt.*;

/**
 * 圆类
 * x,y为public 表示可以获取圆心坐标
 * r为public 表示用户不能获取半径
 * vx,vy为x轴，y轴的移动速度
 */
public class Circle {
    public int x;
    public int y;
    private int r;
    public int vx;
    public int vy;

    public boolean isFill = false;          // true 变实心圆

    public Circle(int x, int y, int r, int vx, int vy) {
        this.x = x;
        this.y = y;
        this.r = r;
        this.vx = vx;
        this.vy = vy;
    }

    // 设置获取R的方法
    public int getR() {
        return r;
    }

    // 设置速度
    public void move(int minx, int miny, int maxx, int maxy) {
        x += vx;
        y += vy;
        checkCollision(minx, miny, maxx, maxy);
    }

    // 碰撞检测
    public void checkCollision(int minx, int miny, int maxx, int maxy) {
        if (x - r < minx) {
            x = r;
            vx = -vx;
        }
        if (x + r >= maxx) {
            x = maxx - r;
            vx = -vx;
        }
        if (y - r < miny) {
            y = r;
            vy = -vy;
        }
        if (y + r >= maxy) {
            y = maxy - r;
            vy = -vy;
        }
    }

    public boolean contain(Point p) {
        return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y) <= r * r;
    }

}
