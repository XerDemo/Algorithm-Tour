import java.awt.*;
import java.awt.geom.Ellipse2D;

// 帮助类 且不希望用户能实列化这个类 因此构造方法 private
public class AlgoVisHelper {
    // private 类型 不希望用户可以实列化 AlgoVisHelper这个类
    private AlgoVisHelper() {
    }

    // 定义线条粗细的方法  static静态的可以供其它类调用
    public static void setStrokeWidth(Graphics2D g2d, int width) {
        int strokeWidth = width;                       // 设置笔画粗细
        g2d.setStroke(new BasicStroke(strokeWidth, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND)); //BasicStroke.CAP_ROUND:线段端点圆形   BasicStroke.JOIN_ROUND：折线端点圆形
    }

    // 绘制空心圆形的方式 static
    public static void setStrokeCircle(Graphics2D g2d, int x, int y, int r) {
        Ellipse2D circle = new Ellipse2D.Float(x - r, y - r, 2 * r, 2 * r);  //设置圆形
        g2d.draw(circle);
    }

    // 绘制实心圆形的方式 static
    public static void setfillCircle(Graphics2D g2d, int x, int y, int r) {
        Ellipse2D circle = new Ellipse2D.Float(x - r, y - r, 2 * r, 2 * r);  //设置圆形
        g2d.fill(circle);
    }

    // 为了统一写法 把颜色也封装起来
    public static void setColor(Graphics2D g2d, Color color) {
        g2d.setColor(color);
    }

    public static void pause(int t){
        try {
            Thread.sleep(t);
        } catch (InterruptedException e) {
            System.out.println("sleep is error.\n");
        }
    }


}
