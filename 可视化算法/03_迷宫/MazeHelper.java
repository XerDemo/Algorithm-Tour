import javax.swing.*;
import java.awt.*;
import java.awt.geom.*;

import java.lang.InterruptedException;

public class MazeHelper {

    private MazeHelper(){}
    // copy的一套google配色方案 idea和eclipse的配色不好看
    public static final Color Red = new Color(0xF44336);
    public static final Color Pink = new Color(0xE91E63);
    public static final Color Purple = new Color(0x9C27B0);
    public static final Color DeepPurple = new Color(0x673AB7);
    public static final Color Indigo = new Color(0x3F51B5);
    public static final Color Blue = new Color(0x2196F3);
    public static final Color LightBlue = new Color(0x03A9F4);
    public static final Color Cyan = new Color(0x00BCD4);
    public static final Color Teal = new Color(0x009688);
    public static final Color Green = new Color(0x4CAF50);
    public static final Color LightGreen = new Color(0x8BC34A);
    public static final Color Lime = new Color(0xCDDC39);
    public static final Color Yellow = new Color(0xFFEB3B);
    public static final Color Amber = new Color(0xFFC107);
    public static final Color Orange = new Color(0xFF9800);
    public static final Color DeepOrange = new Color(0xFF5722);
    public static final Color Brown = new Color(0x795548);
    public static final Color Grey = new Color(0x9E9E9E);
    public static final Color BlueGrey = new Color(0x607D8B);
    public static final Color Black = new Color(0x000000);
    public static final Color White = new Color(0xFFFFFF);

    // 绘制空心矩形
    public static void strokeRectangle(Graphics2D g, int x, int y, int w, int h){
        Rectangle2D rectangle = new Rectangle2D.Double(x, y, w, h);
        g.draw(rectangle);
    }

    // 绘制实心矩形
    public static void fillRectangle(Graphics2D g, int x, int y, int w, int h){
        Rectangle2D rectangle = new Rectangle2D.Double(x, y, w, h);
        g.fill(rectangle);
    }
    // 设置颜色
    public static void setColor(Graphics2D g, Color color){
        g.setColor(color);
    }

    // 设置线程休眠
    public static void pause(int t) {
        try {
            Thread.sleep(t);
        }
        catch (InterruptedException e) {
            System.out.println("Error sleeping");
        }
    }
}