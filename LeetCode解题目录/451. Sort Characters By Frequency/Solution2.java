import java.util.*;

public class Solution2 {
    public String frequencySort(String s) {
        int[] hash = new int[256];
        int max = 0;
        for (Character c : s.toCharArray()) {
            hash[c]++;
            max = Math.max(max, hash[c]);
        }

        List<Character>[] buckets = new List[max + 1];
        for (int i = 0; i < hash.length; ++i) {
            int index = hash[i];
            while (hash[i] > 0) {
                if (buckets[index] == null) {
                    buckets[index] = new ArrayList<>();
                }
                buckets[index].add((char) i);
                hash[i]--;
            }
        }

        StringBuffer res = new StringBuffer();
        for (int i = max; i > 0; --i) {
            if (buckets[i] != null) {
                for (int j = 0; j < buckets[i].size(); ++j) {
                    res.append(buckets[i].get(j));
                }
            }
        }
        return res.toString();

    }

    public static void main(String[] args) {
        String s = "aaaabcc";
        System.out.println(new Solution2().frequencySort(s));
    }
}
