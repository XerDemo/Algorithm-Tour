import java.util.Stack;

public class Solution {
    // 时间复杂度O(N)   空间复杂度O(s.length)
    public boolean isValid(String s) {
        char[] arr = s.toCharArray();
        Stack<Character> stack = new Stack<>();
        for (int i= 0; i<arr.length; ++i) {
            if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[') {
                stack.push(arr[i]);
            }else{
                if (stack.size() == 0){
                    return false;
                }
                char p = stack.pop();
                char match;
                if (arr[i] == ')') {
                    match = '(';
                } else if (arr[i] == ']') {
                    match = '[';
                } else {
                    match = '{';
                }
                if (match != p) {
                    return false;
                }
            }
        }
        // 最后栈不空说明不匹配
        if (stack.size() != 0) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(new Solution().isValid("()[]{}"));
    }
}
