package 算法.动态规划;

// 计算 100!的阶乘
public class Demo3_阶乘_自底向上 {
    static double[] dp;

    public static void main(String[] args) {
        long statrTime = System.currentTimeMillis();
        int n = 10;
        dp = new double[n+1];

        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] * i;
        }
        System.out.println(n + "的阶乘：" + dp[n]);
        System.out.println("Time:" + (System.currentTimeMillis() - statrTime) + "ms");
    }
}
