public class Solution2 {
    // 时间复杂度O(N)  空间复杂度O(1)  双指针之滑动窗口
    public int minSubArrayLen(int s, int[] nums) {
        int left = 0, right = 0;       // [left, right) 左闭右开区间 存放的是满足sun >=s 的元素
        int sum = 0;
        int res = Integer.MAX_VALUE;

        while (right < nums.length) {
            sum += nums[right++];
            while (sum >= s){
                res = Math.min(right - left, res);
                sum -= nums[left++];
            }
        }
        return res == Integer.MAX_VALUE ? 0 : res;
    }

    public static void main(String[] args) {
        int[] nums = {2, 3, 1, 2, 4, 3};
        int s = 7;
        System.out.println(new Solution2().minSubArrayLen(s, nums));
    }
}
