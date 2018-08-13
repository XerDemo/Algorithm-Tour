import java.util.Arrays;

public class Solution3 {
	// 时间复杂度 O(N) 空间复杂度O(N)
	public static void moveZeroes(int[] nums) {
		int[] res = new int[nums.length];

		int k = 0;
		// 非零元素存到res[]
		for (int i = 0; i < nums.length; ++i) {
			if (0 != nums[i]) {
				res[k++] = nums[i];
			}
		}

		for (int i = k; i < nums.length; ++i) {
			res[i] = 0;
		}

		for (int i = 0; i < nums.length; ++i) {
			nums[i] = res[i];
		}
	}

	public static void main(String[] args) {
		int[] nums = { 0, 1, 0, 3, 12 };
		moveZeroes(nums);
		System.out.println(Arrays.toString(nums));
	}
}
