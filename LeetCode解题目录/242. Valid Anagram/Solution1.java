public class Solution1 {
    // 时间复杂度O(N)
    public boolean isAnagram(String s, String t) {
        int[] hash = new int[256];      //来存放该字符出现的频率
        // 统计t中字符出现的频率  hash['a'] = hash[97]
        for (char ch : t.toCharArray()) {
            hash[ch]++;
        }
        // 如果两者长度不相等 说明肯定不是
        if (s.length() != t.length()) {
            return false;
        }
        // 遍历s
        for (int i = 0; i < s.length(); ++i) {
            if (hash[s.charAt(i)] > 0) {     // s.charAt(i)当前出现频率 > 0 说明s中与t都有该字符
                hash[s.charAt(i)]--;         // 对应频率减1
            } else {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String s = "anagram";
        String t = "nagaram";
        System.out.println(new Solution1().isAnagram(s, t));
    }
}
