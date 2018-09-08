import java.util.Arrays;

public class Solution1 {
    // 时间复杂度O(N^2)
    public int threeSumClosest(int[] nums, int target) {
        int res = 99999999;
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; ++i) {
            int left = i + 1, right = nums.length - 1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (Math.abs(sum - target) <= Math.abs(res-target)){
                    res = sum;
                }
                if (sum > target){
                    right--;
                }else if(sum < target){
                    left++;
                }else{
                    return sum;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {-1, 2, 1, -4};
        int target = 1;
        System.out.println(new Solution1().threeSumClosest(nums,target));
    }
}
