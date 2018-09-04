import java.util.HashSet;
import java.util.Set;

public class Solution1 {
    // 时间复杂度 O(N^2)  空间复杂度(m)  m:set的大小
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();       // 记录sum
        while (true) {
            int sum = 0;
            // 分离数位
            while (n > 0) {
                int k = n % 10;
                sum += Math.pow(k, 2);
                n /= 10;
            }
            n = sum;
            // 如果sum == 1 说明是happy number
            if (sum == 1){
                break;
            }
            // 如果set包含sum 说明不是
            if (set.contains(sum)){
                return false;
            }else{  // set不含sum 添加进set 继续
                set.add(sum);
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int n = 19;
        System.out.println(new Solution1().isHappy(n));
    }
}
