import java.util.*;

public class Solution2 {
    // 时间复杂度O(nlog2^n)   双指针
    public int[] intersection(int[] nums1, int[] nums2) {
        // 先对两个数组 进行排序
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        List<Integer> list = new ArrayList<>();  // 存放答案
        int i = 0, j = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] == nums2[j]) {
                list.add(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            }else {
                j++;
            }
        }

        // 将set转为数组
        int[] res = new int[list.size()];
        int index = 0;
        for (Integer x : list) {
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
