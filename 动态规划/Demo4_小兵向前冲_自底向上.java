package 算法.动态规划;

public class Demo4_小兵向前冲_自底向上 {
    static int[][] dp;

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        // n是棋盘的行 m是棋盘的列数
        int n = 20;
        int m = 20;
        dp = new int[n + 1][m + 1];

        // 边界条件
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = 0;           // 行：0 没有棋盘的存在
            dp[1][i] = 1;           // 只要行为1 不管多少列只有一种走法
        }

        for (int j = 1; j <= m; ++j) {
            dp[j][0] = 0;           // 列：0 没有棋盘的存在
            dp[j][1] = 1;           // 只要列为1 不管多少行只有一种走法
        }
        // 状态转移方程 之所以从2不是从1开始 是因为在边界条件中 行、列为1有特殊意义

        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        System.out.println("共有走法：" + dp[n][m]);
        System.out.println("Time:"+(System.currentTimeMillis()-startTime) + "ms");
    }
}
//共有走法：985525432
//        Time:0ms