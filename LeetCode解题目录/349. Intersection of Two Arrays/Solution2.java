import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Solution2 {
    // 时间复杂度O(NlogN)  双指针   java中Arrays.sort();  是快速排序实现
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set = new HashSet<>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i = 0, j = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] > nums2[j]) {
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            }else{
                set.add(nums1[i]);
                i++;
                j++;
            }
        }
        int[] res = new int[set.size()];
        int index = 0;
        for (int k : set) {
            res[index++] = k;
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 2, 1};
        int[] nums2 = {2, 2};
        int[] res = (new Solution2()).intersection(nums1, nums2);
        System.out.println(Arrays.toString(res));
    }
}
