public class Solution3 {
    // 时间复杂度O(N)  空间复杂度O(M) M:字符集的长度 即声明ascii数组大小
    public int lengthOfLongestSubstring(String s) {
        int left = 0, right = 0;         // [left,right)
        int[] ascii = new int[256];
        int res = Integer.MIN_VALUE;
        while (right < s.length()) {
            if (right < s.length() && ascii[s.charAt(right)] == 0) {
                ascii[s.charAt(right++)]++;
            } else {
                ascii[s.charAt(left++)]--;
            }
            res = Math.max(res, right - left);
        }
        return res == Integer.MIN_VALUE ? 0 : res;
    }

    public static void main(String[] args) {
        String s = "abcabcbb";
        System.out.println(new Solution3().lengthOfLongestSubstring(s));
    }
}
