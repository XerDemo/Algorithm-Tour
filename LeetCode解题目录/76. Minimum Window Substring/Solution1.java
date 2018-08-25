public class Solution1 {
    // 时间复杂度O(N)   双指针之滑动窗口
    public String minWindow(String s, String t) {
        int[] hash = new int[256];              // 建立哈希表  hash['a'] 就是hash[97]
        int left = 0, right = 0;                // [left,right)  滑动窗口区间为左闭右开区间
        // 将t中字符出现的次数 加入hash[]
        for (int i = 0; i < t.length(); ++i) {
            hash[t.charAt(i)]++;
        }

        int minLength = Integer.MAX_VALUE;      // 当找到符合答案的滑动窗口时 记录其窗口长度
        int minStart = 0;                       // 当找到符合答案的滑动窗口时 记录其起始位置
        int count = 0;                          // 计数器

        while (right < s.length()) {
            // 不管if()里面条件是否满足  right指向的当前元素始终频率--（所以只要不是t中的元素出现的频率肯定是负数）  right++
            // 如果right指向当前的元素频率>=1 此元素也在t中  count++
            if (hash[s.charAt(right++)]-- >= 1) {
                count++;
            }

            // t中的元素全部找到后
            while (count == t.length()){
                // 更新满足条件的最小滑动区间
                if (right - left < minLength){
                    minLength = right - left;
                    minStart = left;
                }
                // 不管if()里面条件是否满足 left指向的当前元素始终频率++(不是t中的元素频率最多只能加到0,不会超过0)  left++
                // 如果left指向当前的元素频率 = 0  此元素也在t中   count--
                if (hash[s.charAt(left++)]++>= 0){
                    count--;
                }
            }

        }
        return minLength == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLength);
    }

    public static void main(String[] args) {
        String s = "ADOBECODEBANC";
        String t = "ABC";
        System.out.println(new Solution1().minWindow(s, t));
    }
}
