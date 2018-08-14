import java.util.Arrays;

public class Solution1 {
	// 时间复杂度O(N)  空间复杂度O(1)   双指针
	public static int removeDuplicates(int[] nums) {
		if (nums == null || nums.length == 0) {
			return 0;
		}
		
		int slow = 0;  				 // [0,slow]  存放合法数据(答案)
		// 快指针遍历数组  
		for (int fast = 0; fast < nums.length; ++fast) {
			// 当前元素在[0,slow]中未出现，添加到[0,slow)  此处体会数组有序这个条件
			if (nums[slow] != nums[fast]) {
				nums[++slow] = nums[fast];
			}
		}
		return slow+1;
	}

	public static void main(String[] args) {
		int[] nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
		System.out.println(removeDuplicates(nums));
		System.out.println(Arrays.toString(nums));
	}
}
