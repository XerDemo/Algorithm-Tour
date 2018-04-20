package 算法.动态规划;

// 计算10的阶乘
public class Demo3_阶乘_递归 {
    static double f(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }
        return f(n - 1) * n;
    }
    public static void main(String[] args) {
        long statrTime = System.currentTimeMillis();

        int n = 10;
        System.out.println(n+"的阶乘："+f(n));

        System.out.println("Time:" + (System.currentTimeMillis() - statrTime) + "ms");
    }
}
