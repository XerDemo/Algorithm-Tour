import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution1 {
    // 时间复杂度O(n^3)  双指针
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);            // 按从小到大 排序  nums[i] <= nums[j] <= nums[left] <= nums[right]
        List<List<Integer>> res = new ArrayList<>();
        // 遍历第一个指针i 范围[0,nums.length-4]
        for (int i = 0; i < nums.length - 3; ++i) {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {      // 如果四个最小的元素都比target大
                break;
            }
            if (nums[i] + nums[nums.length - 1] + nums[nums.length - 2] + nums[nums.length - 3] < target) {
                // nums[i]和三个最大元素的和都比target小  i++
                continue;
            }
            // 选取第一个元素时 如果发现存在两个或以上的nums[i]相等，选取最后一个，防止在res中出现重复结果
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                // 遍历第二个指针j 范围[i+1, nums.length-3]
                for (int j = i + 1; j < nums.length - 2; ++j) {
                    if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {  // 说明第二个元素nums[j]太大
                        break;
                    }
                    if (nums[i] + nums[j] + nums[nums.length - 1] + nums[nums.length - 2] < target) {
                        // 说明nums[j] 太小 j++
                        continue;
                    }
                    // 在[i+1,nums.length-3]从如果出现连续nums[j]相等 取最后一个 预防在res中出现重复元素
                    if (j == i + 1 || (j > i + 1 && nums[j] != nums[j - 1])) {
                        // 使用双指针
                        int left = j + 1;
                        int right = nums.length - 1;
                        while (left < right) {
                            int sum = nums[i] + nums[j] + nums[left] + nums[right];
                            if (sum == target) {
                                // 取连续相等nums[left]中的最后一个
                                while (left < right && nums[left] == nums[left + 1]) {
                                    left++;
                                }
                                // 取连续相等nums[right]中的从右往左的最后一个
                                while (left < right && nums[right] == nums[right - 1]) {
                                    right--;
                                }
                                List<Integer> list = new ArrayList<>();
                                list.add(nums[i]);
                                list.add(nums[j]);
                                list.add(nums[left++]);
                                list.add(nums[right--]);
                                res.add(list);
                            } else if (sum > target) {
                                right--;
                            } else {
                                left++;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {-1, 0, 1, 2, -1, -4};
        int target = -1;
        List<List<Integer>> res = new Solution1().fourSum(nums, target);
        System.out.println(res);
    }
}
