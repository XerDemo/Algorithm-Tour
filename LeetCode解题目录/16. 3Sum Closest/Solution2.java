import java.util.Arrays;

public class Solution2 {
    // 时间复杂度O(N^2)
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int res = Integer.MAX_VALUE - 999999;
        int left, right;
        for (int i = 0; i < nums.length - 1; i++) {
            left = i + 1;
            right = nums.length - 1;
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == target) return target;
                else if (sum > target) {
                    while (left < right && nums[left] + nums[right] + nums[i] > target) right--;
                    if (Math.abs(nums[i] + nums[left] + nums[right + 1] - target) < Math.abs(res - target))
                        res = nums[i] + nums[left] + nums[right + 1];
                } else {
                    while (left < right && nums[left] + nums[right] + nums[i] < target) left++;
                    if (Math.abs(nums[i] + nums[left - 1] + nums[right] - target) < Math.abs(res - target))
                        res = nums[i] + nums[left - 1] + nums[right];
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {-4, -3, -2, 0, 2, 2, 3, 4};
        int target = 1;
        System.out.println(new Solution2().threeSumClosest(nums, target));
    }
}
