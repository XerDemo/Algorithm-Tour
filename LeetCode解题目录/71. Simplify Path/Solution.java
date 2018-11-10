import java.util.Arrays;
import java.util.Stack;

class Solution {
    // 时间复杂度(N)  空间复杂度O(m) m:path.length
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<>();
        String[] arr = path.split("/");   // 将path以“/”划分的结果放到arr[]字符串数组中

        for (int i = 0; i < arr.length; ++i) {  // 遍历
            if ((arr[i].equals("") || arr[i].equals("."))) {  // 如果遇上"" || "." 跳过
                continue;
            }
            if (!arr[i].equals("..")){                        // 遇上路径名  入栈
                stack.push(arr[i]);
            }
            if (arr[i].equals("..") && stack.size() != 0) {   // 遇上".." 将栈顶元素出栈
                stack.pop();
            }
        }

        StringBuffer sb = new StringBuffer();
        for (String s : stack) {                              // 从栈底遍历栈  不是从栈顶出栈的方式
            sb.append("/" + s);
        }
        return stack.size() == 0 ? "/" : sb.toString();       // 如果栈空 返回 "/"
    }

    public static void main(String[] args) {
        System.out.println(new Solution().simplifyPath("/."));
        System.out.println(new Solution().simplifyPath("/a/../../b/../c//.//"));
    }
}