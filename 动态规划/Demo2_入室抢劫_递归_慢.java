package 算法.动态规划;

/**
 * （之所以设置第0家 是为了方便，也有一定的物理意义，方便了写递归结束条件和 自底向上的边界）
 * <p>
 * 你是一个专业的强盗计划抢劫沿街的房屋。每个房子都有一定的钱藏在里面，阻止你们抢劫他们的唯一的制约因素就是相邻的房屋有保安系统连接
 * 如果两个相邻的房子在同一个晚上被闯入，它会自动联系警方。给出一个代表每个房子的金额的非负整数列表，确定你可以抢劫的最高金额今晚没有提醒警方。
 */

public class Demo2_入室抢劫_递归_慢 {

    static int f(int idx, int[] money) {
        // 递归结束条件 当idx = 0时，代表第一家   idx <0 第0家 不存在为0
        if (idx < 0 ) {
            return 0;
        }
        if (idx == 0) {
            return money[idx] ;
        }
       // 状态转移方程 （递归式） 2种决策：
        return  Math.max(f(idx - 2, money) + money[idx], f(idx-1, money));
    }
    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();

        int n = 35;       //定义35家店
        int[] money = new int[n];
        // money[0]：第一家 、 money[1]：第二家、 money[34]:第35家
        for (int i = 0; i < money.length; ++i) {
            money[i] = i + 1;
        }
        System.out.println("该盗贼总共偷窃：" + f(money.length - 1, money) + "$");

        System.out.println("耗时：" + (System.currentTimeMillis() - startTime) + "ms");
    }

}
