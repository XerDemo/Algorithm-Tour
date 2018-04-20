package 算法.动态规划;

public class Demo3_阶乘_自顶向下 {
    static double[] dp;
    static double f(int n) {
        if (n <= 1) {
            return 1;      //这里是不需要写成memory_arr[n] = 1;
        }
        if (dp[n] > 0) {
            return dp[n];
        }
        return  dp[n] = f(n - 1) * n;

    }
    public static void main(String[] args) {
        long statrTime = System.currentTimeMillis();
        int n = 10;
        dp = new double[n+1];
        System.out.println(n+"的阶乘："+f(n));
        System.out.println("Time:" + (System.currentTimeMillis() - statrTime) + "ms");
    }
}
