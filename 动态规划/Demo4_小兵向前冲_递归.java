package 算法.动态规划;
/**
 *  N*M的棋盘上，小兵要从左下角走到右上角，只能向上或者向右走， 问有多少种走法,每次只能走一步
 */
public class Demo4_小兵向前冲_递归 {
    static int f(int row, int col) {
        //递归结束条件 当row或col=0时  连棋盘都没有
        if (row == 0 || col == 0) {
            return 0;
        }
        //递归结束条件 当row为1时  只有横着的一排棋盘 只有一种走法  当col：1时 只有竖着的一竖棋盘 走法也只有一种
        if (row == 1 || col == 1) {
            return 1;
        }
        //递归式（状态转移方程）
        return f(row - 1, col) + f(row, col - 1);
    }
    public static void main(String[] args) {
        //n是棋盘的行 m是棋盘的列数
        long startTime = System.currentTimeMillis();
        int n = 20;
        int m=20;
        System.out.println("共有走法：" + f(n, m));
        System.out.println("Time:"+(System.currentTimeMillis()-startTime) + "ms");
    }
}
