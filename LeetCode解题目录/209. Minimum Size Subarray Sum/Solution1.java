public class Solution1 {
    // 暴力破解 时间复杂度O(N^2)  空间复杂度O(1)
    public int minSubArrayLen(int s, int[] nums) {
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; ++i) {
            int sum = 0;
            for (int j = i; j < nums.length; ++j) {
                sum += nums[j];
                if (sum >= s) {
                    res = Math.min(j - i + 1, res);
                }
            }
        }
        return res == Integer.MAX_VALUE? 0 : res;
    }

    public static void main(String[] args) {
        int[] nums = {2, 3, 1, 2, 4, 3};
        int s = 7;
        System.out.println(new Solution1().minSubArrayLen(s, nums));
    }
}
