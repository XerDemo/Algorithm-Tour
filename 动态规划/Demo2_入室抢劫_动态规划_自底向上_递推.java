package 算法.动态规划;

public class Demo2_入室抢劫_动态规划_自底向上_递推 {
    static int[] dp;

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        int n = 35;
        // money[0]：第一家 、 money[1]：第二家、 money[199]:第200家
        int[] money = new int[n];
        for (int i = 0; i < money.length; ++i) {
            money[i] = i+1;
        }

        // 当money数组元素为0 即没有店 直接返回0
        if (money.length == 0) {
            System.out.println("0");
            return;
        }
        // 防止 dp[1]越界 如果使用一家店 会越界
        if (money.length == 1) {
            System.out.println(money[0]);
            return;
        }

        dp = new int[n];
        dp[0] = money[0];
        dp[1] = Math.max(money[0], money[1]);
        for (int i=2; i<dp.length; ++i) {
            dp[i] = Math.max(dp[i - 2] + money[i], dp[i-1]);
        }

        System.out.println("该盗贼总共偷窃："+dp[money.length-1] +"$");

        System.out.println("耗时：" +(System.currentTimeMillis() - startTime)+"ms" );
    }
}
