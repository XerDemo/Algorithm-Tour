import java.util.*;

public class Solution2 {

    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> list = new ArrayList<>();
        Map<Character, Integer> ms = new HashMap<>();
        Map<Character, Integer> mp = new HashMap<>();
        Vector v = new Vector();
        for (int i =0; i<p.length();++i) {
            mp.put(p.charAt(i), mp.getOrDefault(p.charAt(i), 0) + 1);
        }

        int left = 0, right = 0;
        while (right < s.length()){
            ms.put(s.charAt(right), ms.getOrDefault(s.charAt(right), 0) + 1);
            right++;
            if (right - left == p.length()){
                if (ms.equals(mp)) {
                    list.add(left);
                }
                char ch = s.charAt(left);
                if (ms.get(ch) > 1){
                    ms.put(ch, ms.get(ch)-1);
                }else{
                    ms.remove(ch);
                }
                left++;
            }
        }
        return list;
    }

    public static void main(String[] args) {
        String s = "cbaebabacd";
        String p = "abc";
        System.out.println(new Solution2().findAnagrams(s, p));
    }
}
