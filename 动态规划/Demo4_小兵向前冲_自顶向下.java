package 算法.动态规划;

public class Demo4_小兵向前冲_自顶向下 {
    static int[][] dp;         //二维记忆数组
    static int f(int row, int col) {
        if (row == 0 || col == 0) {
            return 0;
        }
        if (row == 1 || col == 1) {
            return 1;
        }
        if (dp[row][col] > 0) {
            return dp[row][col];
        }
        //递归式（状态转移方程）
        return dp[row][col] =  f(row - 1, col) + f(row, col - 1);
    }
    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        //n是棋盘的行 m是棋盘的列数
        int n = 20;
        int m= 20;
        dp = new int[n + 1][m + 1];
        System.out.println("共有走法：" + f(n, m));
        System.out.println("Time:"+(System.currentTimeMillis()-startTime) + "ms");
    }
}
//共有走法：985525432
//        Time:0ms