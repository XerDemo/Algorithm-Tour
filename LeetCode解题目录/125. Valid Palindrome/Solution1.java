public class Solution1 {
    // 时间复杂度 O(N)   空间复杂度O(1)    双指针之对撞指针
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {        // 两者还未相遇
            // 从i向右扫描   如果不是字母或数字i++; i<j 是为了在i++的过程中 i始终小于j
            while (i < j && !Character.isLetterOrDigit(s.charAt(i))) {
                i++;
            }
            // 从j向左扫描   如果不是字母或数字j--; i<j 是为了在j--的过程中 i始终小于j
            while (i < j && !Character.isLetterOrDigit(s.charAt(j))) {
                j--;
            }
            // 如果i>=j 说明已经相遇
            if (i >= j) {
                break;
            }
            // 此时i,j指向的都是字母或数字 看两者是否相等 不等说明不是回文数
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            // 如果i,j都指向的是数字或字母 上面的两个while不会执行 需要手动的i++,j--
            i++;
            j--;
        }
        return true;
    }

    public static void main(String[] args) {
        String s = "A man, a plan, a canal: Panama";
        System.out.println(new Solution1().isPalindrome(s));
    }
}
