
//斐波那契：0，1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233，377，610，987，1597，2584，4181。。。。。
//纯递归很简单 不多说
public class Demo1_斐波那契_递归 {
    public  static  int f(int n){
        //递归结束条件
        if (n==0){
            return 0;
        }
        if (n==1){
            return 1;
        }
        //状态转移方程 （递归式）
        return  f(n-1)+f(n-2);
    }
    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        // 打印第0项 - 第299项   发现纯递归 好长时间都递归不出来
        for (int i = 0; i < 300; ++i) {
            System.out.print(f(i) + "  ");
        }

        System.out.println("Time：" + (System.currentTimeMillis()-start) + "ms");
    }
}
