import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution2 {
    // 时间复杂度O(Nlog2^N) + O(N^2)      排序 + 双指针
    // 优化Solution1  不需要set去重 直接在找的时候重复元素不添加到res中
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {      // 防止res中有重复的结果
                int left = i + 1;
                int right = nums.length - 1;
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (sum == 0) {
                        List<Integer> list = new ArrayList<>();
                        while (left < right && nums[left] == nums[left + 1]) {   // 防止res中有重复的结果
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) { // 防止res中有重复的结果
                            right--;
                        }
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
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {-1, 0, 1, 2, -1, -4};
        List<List<Integer>> res = new Solution2().threeSum(nums);
        System.out.println(res);
    }
}
