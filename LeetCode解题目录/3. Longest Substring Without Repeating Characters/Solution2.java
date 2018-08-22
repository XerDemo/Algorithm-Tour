import java.util.HashMap;
import java.util.Map;

public class Solution2 {
    // 时间复杂度O(N)
    public int lengthOfLongestSubstring(String s) {
        int left = 0, right = 0;                        // [left,right):存放无重复元素
        Map<Character, Integer> map = new HashMap<>();
        int res = Integer.MIN_VALUE;

        while (right < s.length()) {
            // 如果map中不含当前元素, 将当前元素添加进map,对应频率+1,并且right往后移
            if (right < s.length() && !map.containsKey(s.charAt(right))){
                map.put(s.charAt(right++), 1);
            }else{  // 如果map中发现当前元素在[left,right)中已经出现过  将left对应元素频率--，left向后移动
                map.remove(s.charAt(left++));
            }
            res = Math.max(res, right - left);   // 更新结果
        }
        return res == Integer.MIN_VALUE ? 0 : res;
    }

    public static void main(String[] args) {
        String s = "abcabcbb";
        System.out.println(new Solution2().lengthOfLongestSubstring(s));
    }
}
