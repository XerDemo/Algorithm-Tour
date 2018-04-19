package 算法.动态规划;
/*
1.动态规划是建立在递归的基础之上的
2.动态规划就是 就是创建数组或Map记忆(保存)已经出现过的结果(子问题)(指的是全部的结果都被保存了)  Map的底层架构也是数组，当存入数组的不是整数就用Map  Array[1.5]显然不行
3.递归 就是 原问题 -> 子问题 ->原问题
4.自顶向下就是从f(n) f(n-2).....f(0) 也就是递归
5.自顶向上就是从 f(0) f(n-1) f(n)  也就是递推
*/
/***************动态规划解题步骤************/
//1.设计暴力算法(纯粹的递归)，找到出现多次的结果
//2.设计并存储状态(一维，二维，三维数组，Map)
//3.设计递归式
//4.自底向上计算最优解(编程方式)

public class Demo2_入室抢劫_动态规划_自顶向下_递归 {
     static  int[] dp;                                //设计存储模式 为数组

    static int f(int idx, int[] money) {
        //递归结束条件
        if (idx < 0 ) {
            return 0;
        }
        if (idx == 0) {
            return money[idx] ;
        }

        // 如果已经算过 直接return 因为我初始化时每个元素都为-1 ，由题目可得不存在一共只抢了负数金额得情况  所以如果不等于-1 或 (>=0) 代表算过
        if (dp[idx] != -1) {
            return dp[idx];
        }
        //状态转移方程  递归式
        return dp[idx] = Math.max(f(idx - 2, money) + money[idx], f(idx-1, money));

    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        int n = 35;
        // money[0]：第一家 、 money[1]：第二家、 money[199]:第200家
        int[] money = new int[n];
        for (int i = 0; i < money.length; ++i) {
            money[i] = i+1;
        }

        dp = new int[n];
        //因为java在new int类型的数组时 已经自动帮你初始化为0
        //所以如果记忆数组（记事本）里面 dp[idx] ！= 0 代表算过 但是此时 抢劫得金额可以为总共抢到了0元 dp[idx]=0， 此时是通过计算得来的  不是初始化来的
        // 初始化为一个不可能算到的值 由题意得改抢劫得金额不可能为负数  所以我初始化为 -1
        for (int i=0; i<dp.length;++i) {
            dp[i] = -1;
        }

        System.out.println("该盗贼总共偷窃："+f(money.length-1, money) +"$");

        System.out.println("耗时：" +(System.currentTimeMillis() - startTime)+"ms" );
    }
}
