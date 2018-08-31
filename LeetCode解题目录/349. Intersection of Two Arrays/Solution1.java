import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Solution1 {
    // 时间复杂度O(N)  空间复杂度O(N):两个set+res[]
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();        // 用来存放 nums2
        for (int x:nums2){                         // 将nums2添加到set(此时nums2的重复元素被过滤)
            set.add(x);
        }

        Set<Integer> resultSet = new HashSet<>();  // 存放两数组之间的公共元素(重复的会被过滤)
        // 遍历nums1 看set中是否含有此元素
        for (int i =0; i<nums1.length; ++i) {
            if (set.contains(nums1[i])) {
                resultSet.add(nums1[i]);
            }
        }

        // 将resultSet转为数组
        int[] res = new int[resultSet.size()];
        int index = 0;
        for (int x: resultSet){
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
