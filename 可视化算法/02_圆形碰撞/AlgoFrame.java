import javax.swing.*;
import java.awt.*;
import java.awt.geom.Ellipse2D;

public class AlgoFrame extends JFrame {
    private int canvasWidth;            // 绘制面板的宽
    private int canvasHight;            // 绘制面板的高

    public AlgoFrame(String title, int canvasWidth, int canvasHight) {
        super(title);

        this.canvasWidth = canvasWidth;
        this.canvasHight = canvasHight;

        // new出对应的绘制面板
        canvasPanel panel = new canvasPanel();
        // panel.setPreferredSize(new Dimension(canvasWidth, canvasHight));
        setContentPane(panel);  // 将panel添加到 AlgoFrame中
        pack();                 // 调整此窗口的大小，以适合其子组件的首选大小和布局

        // 设置窗口可见
        setVisible(true);
        // 设置点击窗口的关闭能自动退出
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // 设置窗口不可改变大小   此时最大化已经变成灰色
        setResizable(false);
    }

    public int getCanvasWidth() {
        return canvasWidth;
    }

    public int getCanvasHight() {
        return canvasHight;
    }

    //
    public Circle[] circles;

    public void render(Circle[] circles) {
        this.circles = circles;
        repaint();
    }


    // 设置绘制面板 panel
    public class canvasPanel extends JPanel {

        // 设置双缓存
        public canvasPanel() {
            super(true);
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            // g.drawOval(50,50,300,300);
            // Graphics里面的方法 有点老 使用Graphics2D会更好一点
            Graphics2D g2d = (Graphics2D) g;            // 强制转化

            /***********抗锯齿***************/

            //RenderingHints.KEY_ANTIALIASING:决定是否使用抗锯齿     VALUE_ANTIALIAS_ON：打开抗锯齿
            RenderingHints hints = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g2d.addRenderingHints(hints);

            /***********具体绘制*************/

            AlgoVisHelper.setStrokeWidth(g2d, 5);
            AlgoVisHelper.setColor(g2d, Color.yellow);
            for (Circle cir : circles) {
                if (!cir.isFill) {
                    AlgoVisHelper.setStrokeCircle(g2d, cir.x, cir.y, cir.getR());
                } else {
                    AlgoVisHelper.setfillCircle(g2d, cir.x, cir.y, cir.getR());
                }

            }
        }

        // 自动设置画布大小
        @Override
        public Dimension getPreferredSize() {
            return new Dimension(canvasWidth, canvasHight);
        }
    }

}
