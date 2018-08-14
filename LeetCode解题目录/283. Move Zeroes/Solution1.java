import java.util.Arrays;
public class Solution1 {
	// 时间复杂度 O(N)   空间复杂度O(1)    双指针
	public static void moveZeroes(int[] nums) {
		int slow = 0; 		// nums中, [0...slow)的元素均为非0元素
		for (int fast = 0; fast < nums.length; ++fast) {
			if (0 != nums[fast]) {
				nums[slow++] = nums[fast];
			}
		}
		
		// [slow , nums.length) 存放0
		for (int i = slow; i < nums.length; ++i) {
			nums[i] = 0;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 0, 1, 0, 3, 12 };
		moveZeroes(nums);
		System.out.println(Arrays.toString(nums));
	}
}
