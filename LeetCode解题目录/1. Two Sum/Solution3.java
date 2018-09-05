import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution3 {
    // 时间复杂度O(N)
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            if (map.containsKey(target - nums[i])) {
                res[1] = i;
                res[0] = map.get(target - nums[i]);
                break;
            }else {
                map.put(nums[i], i);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {3, 2, 4};
        int target = 6;
        System.out.println(Arrays.toString(new Solution3().twoSum(nums, target)));
    }
}
