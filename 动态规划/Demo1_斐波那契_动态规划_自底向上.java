package 算法.动态规划;
//思路：
//        首先将递归式搬下来，加上for循环 看递归式里是i-几 设置初始条件 把之前跟数组赋初值的for循环去掉
//        1.arr[n]=f(n-1)+f(n-2);
//        初始条件：arr[0]=0;arr[1]=1;
//
//        for(int i=2;i<arr.length;++i){
////          arr[n] = f(n - 1) + f(n - 2); 搬下来  n-2推出for里的i要从2开始
////          arr[n]=arr[n-1]+arr[n-2];   对着f函数的返回值看f(n-1)不就是arr[n-1]
//        arr[i]=arr[i-1]+arr[i-2]  //将n修改为i
//        }


public class Demo1_斐波那契_动态规划_自底向上 {
    public static long[] dp;                   //设计存储模式 一维数组

    public static void main(String[] args) {
        long start = System.currentTimeMillis();

        dp = new long[300];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < 300; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
            // return arr[n] = f(n - 1) + f(n - 2);   //状态转移方程
        }

        for (int i=0; i<300; ++i) {
            System.out.print(dp[i] + "  ");
        }
        System.out.println("\nTime：" + (System.currentTimeMillis()-start) + "ms");
    }
}

