import java.util.HashMap;
import java.util.Map;

public class Solution1 {
    // 时间复杂度O(N)
    public boolean isIsomorphic(String s, String t) {
        Map<Character, Character> map = new HashMap<>();

        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); ++i) {
            char chs = s.charAt(i);
            char cht = t.charAt(i);

            if (map.containsKey(chs)) {
                if (!map.get(chs).equals(cht)) {
                    return false;
                }
            } else {
                if (map.containsValue(cht)){
                    return false;
                }
                map.put(chs, cht);
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String s = "egg";
        String t = "add";
        System.out.println(new Solution1().isIsomorphic(s, t));
    }
}
