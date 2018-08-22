import java.util.HashSet;
import java.util.Set;

public class Solution1 {
    // 时间复杂度O(N^2)    空间复杂度O(set的大小*s的大小)
    public int lengthOfLongestSubstring(String s) {
        int res = Integer.MIN_VALUE;
        for (int i = 0; i < s.length(); ++i) {
            // 创建hashset判断[i,j]之间是否有重复元素
            Set<Character> set = new HashSet();
            for (int j = i; j < s.length(); ++j) {
                if (set.contains(s.charAt(j))) {    // 如果有重复元素 终止当前循环 判断[i+1,j]之间是否有重复元素
                    break;
                }
                set.add(s.charAt(j));               // 如果set中不含当前元素 将当前元素添加进set中
                res = Math.max(j - i + 1, res);     // 更新结果
            }
        }
        return res == Integer.MIN_VALUE ? 0 : res;
    }

    public static void main(String[] args) {
        String s = "abcabcbb";
        System.out.println(new Solution1().lengthOfLongestSubstring(s));
    }
}
