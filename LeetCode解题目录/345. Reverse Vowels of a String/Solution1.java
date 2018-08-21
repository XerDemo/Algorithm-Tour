public class Solution1 {
    // 时间复杂度O(N)   空间复杂度O(N)
    public String reverseVowels(String s) {
        char[] res = s.toCharArray();
        String vowels = "aeiouAEIOU";       // 元音字母
        int i = 0;
        int j = res.length-1;
        // 只要i,j两者还未相遇
        while (i < j){
            // 如果i指向的不是元音字母 i++; i<j是为了确保在i++的过程中始终满足 i<j
            while (i < j && !vowels.contains(res[i]+"")) {
                i++;
            }
            // 如果j指向的不是元音字母 j--; i<j是为了确保在j--的过程中始终满足 i<j
            while (i < j && !vowels.contains(res[j]+"")) {
                j--;
            }
            // 此时i,j指向的都是元音字母 交换
            char temp = res[i];
            res[i] = res[j];
            res[j] = temp;
            // 如果i,j指向的是元音字母 上面的两个while不会执行 需手动移动i,j指针
            i++;
            j--;
        }
        return new String(res);
    }

    public static void main(String[] args) {
        String s = "leetcode";
        System.out.println(new Solution1().reverseVowels(s));
    }
}
