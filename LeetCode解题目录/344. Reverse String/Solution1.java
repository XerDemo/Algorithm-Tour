public class Solution1 {
    // 时间复杂度O(N)  空间复杂度O(N) 主要是开辟了res数组
    public String reverseString(String s) {
        int i = 0;
        int j = s.length() - 1;
        char[] res = s.toCharArray();
        while (i < j){
            char temp = res[i];
            res[i] = res[j];
            res[j] = temp;
            i++;
            j--;
        }
        return new String(res);
    }

    public static void main(String[] args) {
        String s = "A man, a plan, a canal: Panama";
        System.out.println(new Solution1().reverseString(s));
    }
}
