import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Solution1 {
<<<<<<< HEAD
    // 时间复杂度O(N)  空间复杂度O(N):两个set+res[]
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();        // 用来存放 nums2
        for (int x:nums2){                         // 将nums2添加到set(此时nums2的重复元素被过滤)
            set.add(x);
        }

        Set<Integer> resultSet = new HashSet<>();  // 存放两数组之间的公共元素(重复的会被过滤)
        // 遍历nums1 看set中是否含有此元素
        for (int i =0; i<nums1.length; ++i) {
=======
    // 时间复杂度O(N)  使用set容器:无序，唯一
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        for (int i : nums2) {                     // 将nums2的元素添加进set
            set.add(i);
        }

        Set<Integer> resultSet = new HashSet<>(); // 存放最终结果
        // 遍历nums1, 发现set中含有nums1的元素，则将该元素添加到resultSet
        for (int i = 0; i < nums1.length; ++i) {
>>>>>>> 16d1182c61e129229d3f72a435278a6170154240
            if (set.contains(nums1[i])) {
                resultSet.add(nums1[i]);
            }
        }

        // 将resultSet转为数组
        int[] res = new int[resultSet.size()];
        int index = 0;
<<<<<<< HEAD
        for (int x: resultSet){
            res[index++] = x;
=======
        for (int i : resultSet) {
            res[index++] = i;
>>>>>>> 16d1182c61e129229d3f72a435278a6170154240
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
