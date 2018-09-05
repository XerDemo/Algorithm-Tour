
import java.util.Arrays;
public class Solution2 {
    // 二分搜索非递归
    public int BinarySearch1(int[] nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;      // 没找到：-1
    }

    // 二分搜索递归
    public int BinarySearch2(int[] nums, int left, int right, int target) {
        if (left > right) {
            return -1;  // 没找到
        }

        int mid = left + (right - left) / 2;
        if (nums[mid] < target){
            return BinarySearch2(nums, mid + 1, right, target);
        }else if (nums[mid] > target){
            return BinarySearch2(nums, left, mid - 1, target);
        }else{
            return mid;
        }
    }

    // 时间复杂度O(Nlog2^N)
    public int[] twoSum(int[] nums, int target) {
        int[] tempArr = Arrays.copyOf(nums, nums.length);
        Arrays.sort(nums);
        int[] res = new int[2];

        int left = 0, right = 0;
        for (; left < nums.length; ++left) {
            right = BinarySearch1(nums, left + 1, nums.length - 1, target - nums[left]);
            if (right != -1) {
                break;
            }
        }

        for (int i = 0; i < tempArr.length; ++i) {
            if (tempArr[i] == nums[left]) {
                res[0] = i;
                break;
            }
        }

        for (int i = tempArr.length - 1; i >= 0; --i) {
            if (tempArr[i] == nums[right]) {
                res[1] = i;
                break;
            }
        }

        if (res[0] > res[1]) {
            int t = res[0];
            res[0] = res[1];
            res[1] = t;
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {-1, -2, -3, -4, -5};
        int target = -8;
        System.out.println(Arrays.toString(new Solution2().twoSum(nums, target)));
    }
}
