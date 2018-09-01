import java.util.*;

public class Solution1 {
    // 时间复杂度O(N)   利用map 跟个数有关
    public int[] intersection(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<>(); // 用来存放 nums2
        for (int x:nums2){                           // 将nums2添加到map
            map.put(x, map.getOrDefault(x, 0) + 1);
        }

        List<Integer> list = new ArrayList<>();
        // 遍历nums1 看map中是否含有此元素
        for (int i =0; i<nums1.length; ++i) {
            if (map.containsKey(nums1[i]) && map.get(nums1[i]) > 0) {
                list.add(nums1[i]);
                map.put(nums1[i], map.get(nums1[i]) - 1);    // 该元素对应次数-1
            }
        }

        // 将list转为数组
        int[] res = new int[list.size()];
        int index = 0;
        for (int x: list){
            res[index++] = x;
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 2, 1};
        int[] nums2 = {2, 2};
        int[] res = (new Solution1()).intersection(nums1, nums2);
        System.out.println(Arrays.toString(res));
    }
}
