import java.awt.Graphics2D;
import java.awt.Graphics;
import java.awt.Dimension;
import java.awt.RenderingHints;

import javax.swing.*;

public class MazeFrame extends JFrame {

    private int canvasWidth;						// 画布的宽度
    private int canvasHeight;                       // 画布的高度
    
    public MazeFrame(String title, int canvasWidth, int canvasHeight) {

        super("迷宫动画演示");         // 设置标题

        this.canvasWidth = canvasWidth;
        this.canvasHeight = canvasHeight;

        AlgoCanvas canvas = new AlgoCanvas();
        setContentPane(canvas);
        
        setResizable(false);   // 设置窗口可见
        pack();    // 在setResizable(false)后进行pack()，防止在Windows下系统修改frame的尺寸
        // 具体参见：http://coding.imooc.com/learn/questiondetail/26420.html

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  // 设置点击窗口的关闭能自动退出
        setVisible(true);
    }

    public MazeFrame(String title) {

        this(title, 1024, 768);
    }

    public int getCanvasWidth() {
        return canvasWidth;
    }

    public int getCanvasHeight() {
        return canvasHeight;
    }
    
    private MazeData data;

    public void render(MazeData data) {
        this.data = data;
        repaint();           
    }
    
    // 创建画板
    private class AlgoCanvas extends JPanel {

        public AlgoCanvas() {
            // 设置双缓存
            super(true);
        }

        @Override
        public void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2d = (Graphics2D) g;

            // 设置抗锯齿   
            RenderingHints hints = new RenderingHints(
                    RenderingHints.KEY_ANTIALIASING,
                    RenderingHints.VALUE_ANTIALIAS_ON);
            hints.put(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY);
            g2d.addRenderingHints(hints);

            // 具体绘制
            int w = canvasWidth / data.M();   // 每个迷宫格子的宽度
            int h = canvasHeight / data.N();  // 每个迷宫格子的高度
            
            // 开始绘制
            for (int i = 0; i < data.N(); ++i) {
                for (int j = 0; j < data.M(); ++j) {
                    if (data.getMaze(i, j) == MazeData.ROAD) {			// 如果是路 我将其绘制 白色
                        MazeHelper.setColor(g2d, MazeHelper.White);
                    } else {
                        MazeHelper.setColor(g2d, MazeHelper.LightBlue); // 不是路 将其绘制成亮蓝色
                    }
                    
                    // 如果
                    if (data.path[i][j]) {
                        MazeHelper.setColor(g2d, MazeHelper.Yellow);
                    }

                    if (data.result[i][j]) {
                        MazeHelper.setColor(g2d, MazeHelper.Red);
                    }

                    MazeHelper.fillRectangle(g2d, j * w, i * h, w, h);
                }
            }
        }

        @Override
        public Dimension getPreferredSize() {
            return new Dimension(canvasWidth, canvasHeight);
        }
    }
}

