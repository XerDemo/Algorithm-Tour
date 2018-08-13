import java.util.Arrays;
public class Solution1 {
	// 时间复杂度 O(N)   空间复杂度O(1)    双指针
	public static void moveZeroes(int[] nums) {
		int left = 0; 		// [left,right) 存放 非零元素
		for (int right = 0; right < nums.length; ++right) {
			if (0 != nums[right]) {
				nums[left++] = nums[right];
			}
		}
		
		// [right , nums.length) 存放0
		for (int i = left; i < nums.length; ++i) {
			nums[i] = 0;
		}
	}

	public static void main(String[] args) {
		int[] nums = { 0, 1, 0, 3, 12 };
		moveZeroes(nums);
		System.out.println(Arrays.toString(nums));
	}
}
