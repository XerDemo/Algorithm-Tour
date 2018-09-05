import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution1 {
    public String frequencySort(String s) {
        Map<Character, Integer> map = new HashMap<>();
        int max = 0;
        // 将s加入到map中 并记录次数
        for (Character c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
            max = Math.max(max, map.get(c));
        }
        List<Character>[] lists = new List[max + 1];    // 建立链表数量(并不是指真正的链表)  体会+1  lists[0]并没有作用
        // 遍历key  将剩余的元素链到对应位置
        for (Character c : map.keySet()) {
            int index = map.get(c);                     // 链表下标 也对应的是该字母出现的个数
            while (map.get(c) > 0) {
                if (lists[index] == null) {
                    lists[index] = new ArrayList<>();
                }
                lists[index].add(c);
                map.put(c, map.get(c) - 1);
            }
        }

        StringBuffer res = new StringBuffer();          // 将答案放在res中
        // 从lists[max] 开始往 lists[1] 遍历 (1-max中可能出现k，使得lists[k] =null 比如本例中lists[3] = null)
        // lists的索引是该字母出现的次数
        for (int i = max; i > 0; --i) {
            if (lists[i] != null) {
                for (int j = 0; j < lists[i].size(); ++j) {
                    res.append(lists[i].get(j));
                }
            }
        }
        return res.toString();
    }

    public static void main(String[] args) {
        String s = "aaabcc";
        System.out.println(new Solution1().frequencySort(s));
    }
}
