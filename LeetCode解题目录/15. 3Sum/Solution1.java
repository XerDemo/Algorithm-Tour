import java.util.*;

public class Solution1 {
    // 时间复杂度O(Nlog2^N) + O(N^2)      排序 + 双指针
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; ++i) {
            int left = i + 1;
            int right = nums.length - 1;
            // 在[i+1,nums.length-1] 用双指针搜索另外两个元素
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    List<Integer> list = new ArrayList<>();
                    list.add(nums[i]);
                    list.add(nums[left++]);
                    list.add(nums[right--]);
                    res.add(list);
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        Set<List<Integer>> set = new HashSet<>(res);    // set用来给结果 去重
        List<List<Integer>> ans = new ArrayList<>(set); // 将set转list
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {-1, 0, 1, 2, -1, -4};
        List<List<Integer>> res = new Solution1().threeSum(nums);
        System.out.println(res);
    }
}
