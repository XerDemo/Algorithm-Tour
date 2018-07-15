import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

/**
 * c 控制层
 */
public class AlgoVisualizer {
    private Circle[] circles;                    // 数据层(模型)
    private AlgoFrame frame;                     // 视图层

    private boolean flag = true;                 // 动画是否继续运行  true是

    public AlgoVisualizer(int sceneWidth, int sceneHight, int N) {

        /****** 初始化数据 ********/

        int R = 50;
        circles = new Circle[N];
        for (int i = 0; i < N; ++i) {
            // x, y 圆心可以在 sceneWidth * sceneHight这个范围自由出现的位置
            int x = (int) (Math.random() * sceneWidth) - 2 * R + R;
            int y = (int) (Math.random() * sceneHight) - 2 * R + R;
            // vx:x轴的速度 -5 ~ 5  vy:y轴的速度 -5 ~ 5
            int vx = (int) (Math.random() * 11) - 5;
            int vy = (int) (Math.random() * 11) - 5;
            circles[i] = new Circle(x, y, R, vx, vy);
        }

        /******* 初始化视图 ********/

        // java8 引入的新方法 ()->
        // https://blog.csdn.net/renfufei/article/details/24600507
        EventQueue.invokeLater(() -> {
            // 创建窗口
            frame = new AlgoFrame("算法可视化", sceneWidth, sceneHight);

            frame.addKeyListener(new AlgoKeyListener());
            frame.addMouseListener(new AlgoMouseListener());

            // 必须新开一个线程 要不然 不会执行
            new Thread(() -> {

                run();

            }).start();
        });
    }

    /*** 动画逻辑***/
    public void run() {

        while (true) {

            /**** 绘制数据 *******/
            frame.render(circles);
            AlgoVisHelper.pause(20);    // 设置休眠时间 为了是绘制过程不至于速度太快 但也不能太慢 t要适中

            /**** 更新数据 *******/
            if (flag) {
                for (Circle cir : circles) {
                    cir.move(0, 0, frame.getCanvasWidth(), frame.getCanvasHight());
                }
            }
        }
    }

    // 创建一个私有的匿名内部类  实现 按下空格暂停 再按 运动
    private class AlgoKeyListener extends KeyAdapter {
        @Override
        public void keyReleased(KeyEvent e) {
            if (e.getKeyChar() == ' ') {
                flag = !flag;
            }
        }
    }

    // 创建一个私有的匿名内部类 鼠标点击事件
    private class AlgoMouseListener extends MouseAdapter {
        @Override
        public void mousePressed(MouseEvent e) {

            // 减去 窗口菜单的高度 的偏移
            e.translatePoint(0,-(frame.getBounds().height-frame.getCanvasHight())); // y出现负值 不对 日后完善
            // System.out.println(e.getPoint());

            for (Circle cir : circles) {
                if (cir.contain(e.getPoint())) {
                    cir.isFill = !cir.isFill;
                }
            }
        }
    }

    public static void main(String[] args) {
        int sceneWidth = 800;
        int sceneHight = 800;
        int N = 10;
        AlgoVisualizer visualizer = new AlgoVisualizer(sceneWidth, sceneHight, N);
    }
}
