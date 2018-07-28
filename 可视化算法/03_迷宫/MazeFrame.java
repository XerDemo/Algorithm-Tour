import java.awt.Graphics2D;
import java.awt.Graphics;
import java.awt.Dimension;
import java.awt.RenderingHints;

import javax.swing.*;

public class MazeFrame extends JFrame {

    private int canvasWidth;						// �����Ŀ��
    private int canvasHeight;                       // �����ĸ߶�
    
    public MazeFrame(String title, int canvasWidth, int canvasHeight) {

        super("�Թ�������ʾ");         // ���ñ���

        this.canvasWidth = canvasWidth;
        this.canvasHeight = canvasHeight;

        AlgoCanvas canvas = new AlgoCanvas();
        setContentPane(canvas);
        
        setResizable(false);   // ���ô��ڿɼ�
        pack();    // ��setResizable(false)�����pack()����ֹ��Windows��ϵͳ�޸�frame�ĳߴ�
        // ����μ���http://coding.imooc.com/learn/questiondetail/26420.html

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  // ���õ�����ڵĹر����Զ��˳�
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
    
    // ��������
    private class AlgoCanvas extends JPanel {

        public AlgoCanvas() {
            // ����˫����
            super(true);
        }

        @Override
        public void paintComponent(Graphics g) {
            super.paintComponent(g);
            Graphics2D g2d = (Graphics2D) g;

            // ���ÿ����   
            RenderingHints hints = new RenderingHints(
                    RenderingHints.KEY_ANTIALIASING,
                    RenderingHints.VALUE_ANTIALIAS_ON);
            hints.put(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY);
            g2d.addRenderingHints(hints);

            // �������
            int w = canvasWidth / data.M();   // ÿ���Թ����ӵĿ��
            int h = canvasHeight / data.N();  // ÿ���Թ����ӵĸ߶�
            
            // ��ʼ����
            for (int i = 0; i < data.N(); ++i) {
                for (int j = 0; j < data.M(); ++j) {
                    if (data.getMaze(i, j) == MazeData.ROAD) {			// �����· �ҽ������ ��ɫ
                        MazeHelper.setColor(g2d, MazeHelper.White);
                    } else {
                        MazeHelper.setColor(g2d, MazeHelper.LightBlue); // ����· ������Ƴ�����ɫ
                    }
                    
                    // ���
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

