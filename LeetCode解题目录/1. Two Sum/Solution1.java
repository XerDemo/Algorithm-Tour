
import java.util.Arrays;
public class Solution1 {
    // 时间复杂度O（Nlog2^N）
    public int[] twoSum(int[] nums, int target) {
        int[] tempArr = Arrays.copyOf(nums, nums.length);
        Arrays.sort(nums);
        int[] res = new int[2];
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                break;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        // 这里nums[left] + nums[right] 已经等于 target 但是不能直接返回 left，right 因为我们将数组排过序
        // 查找left
        for (int i = 0; i < tempArr.length; ++i) {
            if (tempArr[i] == nums[left]) {
                res[0] = i;
                break;
            }
        }
        // 查找right
        for (int i = tempArr.length-1; i>=0; --i) {
            if (tempArr[i] == nums[right]) {
                res[1] = i;
                break;
            }
        }
        // 如果left > right 交换
        if (res[0] > res[1]){
            int t = res[0];
            res[0] = res[1];
            res[1] = t;
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {-1, -2, -3, -4, -5};
        int target = -8;
        System.out.println(Arrays.toString(new Solution1().twoSum(nums, target)));
    }
}
