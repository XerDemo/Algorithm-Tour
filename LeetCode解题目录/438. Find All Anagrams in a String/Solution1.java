import java.util.ArrayList;
import java.util.List;

public class Solution1 {
    // 时间复杂度O(N)
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        int left = 0, right = 0;      // [left, right)  滑动窗口
        int[] hash = new int[128];    // 声明哈希表  128：ASCII  256:扩展的ASCII
        // hash中存放p中字符出现的次数
        for (int i = 0; i<p.length();++i) {
            hash[p.charAt(i)]++;
        }

        int count = 0;                // 计数器
        while (right < s.length()) {
            // 每次都将当前遍历的元素次数-1 ,那么不属于p里面的字符 出现的频率肯定是负数
            // 当发现当前元素频率大于等于1 说明当前元素是p中的某一个  计数器++
            if (hash[s.charAt(right++)]-- >= 1) {
                count++;
            }
            // 如果计数器等于p的长度 说明找到了符合条件的答案
            if (count == p.length()){
                res.add(left);
            }
            // 如果发现left所在位置元素的频率>=0 说明是p中的某个元素  (不是p中的元素在第一个if时 频率已经是复述了)
            if (right -left == p.length() && hash[s.charAt(left++)]++ >= 0){
                count--;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        String s = "cbaebabacd";
        String p = "abc";
        System.out.println(new Solution1().findAnagrams(s, p));
    }
}
