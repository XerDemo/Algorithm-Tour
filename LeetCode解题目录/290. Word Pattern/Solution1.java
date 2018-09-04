import java.util.HashMap;
import java.util.Map;

public class Solution1 {
    public boolean wordPattern(String pattern, String str) {
        Map<Character, String> map = new HashMap<>();
        String[] res = str.split(" ");

        if (pattern.length() != res.length){
            return false;
        }
        for (int i=0;i<pattern.length();++i) {
            if (map.containsKey(pattern.charAt(i))){
                if (!map.get(pattern.charAt(i)).equals(res[i])) {
                    return false;
                }
            }else{
                if (map.containsValue(res[i])){
                    return false;
                }
                map.put(pattern.charAt(i), res[i]);
            }
        }
        return true;

    }

    public static void main(String[] args) {
        String pattern = "abba";
        String str = "dog cat cat dog";
        System.out.println(new Solution1().wordPattern(pattern, str));
    }
}
