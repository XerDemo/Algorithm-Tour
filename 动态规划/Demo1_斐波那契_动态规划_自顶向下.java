package 算法.动态规划;
//简介:
//      自顶向下 带有记忆功能  就是记忆你有哪些数重复计数 遇到了直接返回之前计算的结果 也叫重叠子问题
//        比如：f(9) = f(8) + f(7)
//              f(8) = f(7) + f(6)
//              f(7) = f(6) + f(5)
//                    省略
//              f(2) = f(1) + f(0)
//              f(7)出现多次 用一个数组dp将f(9)，f(8),...f(0)存起来 先给数组赋值-1(比如) 如果发现f(n)不等于-1 则说明之前已经被计算过 直接return memory_arr[n]的值
//              java中new一个int数组已经帮你初始化了，全为0，所以只要dp[n]的值>0  则说明计算过
//    //解题步骤：
//        1.先暴力 递归  找到冗余
//        2.设计存储模式  一维、二维、多维数组(适用于int[整数])  如果不是整数用Map
//        2.寻找最优子结构  设计递归式(状态转移方程)
//        4.自底向上 最后写成这种编码形式
//        自顶向下粗俗来讲: 就是用设计一个记忆数组（记事本） 保存递归式的结果   判断 是否计算过
//        dp[n] = 递归式  if(dp[n] > 0 ) return dp[n]

public class Demo1_斐波那契_动态规划_自顶向下 {
    public static long[] dp;                   //设计存储模式 一维数组

    public static long f(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        // 如果dp[n] ！= 0 说明 之前算过   直接在记忆数组里面 return dp[n]
        if (dp[n] > 0) {
            return dp[n];
        }
        return dp[n] = f(n - 1) + f(n - 2);   //状态转移方程   递归式
    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        // new 出记忆数组 并在new的同时 将数组元素初始化为0
        dp = new long[300];
        // 采用动态规划后 明显 比之前计算速度快
        for (int i = 0; i < 300; ++i) {
            System.out.print(f(i) + "  ");
        }

        System.out.println("\nTime：" + (System.currentTimeMillis()-start) + "ms");
    }
}


