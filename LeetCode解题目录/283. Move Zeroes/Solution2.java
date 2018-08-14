import java.util.Arrays;

public class Solution2 {
	public static void swap(int[] nums, int i, int j) {
		int t = nums[i];
		nums[i] = nums[j];
		nums[j] = t;
	}
	
	// ʱ�临�Ӷ� O(N) �ռ临�Ӷ�O(1) ˫ָ��
	public static void moveZeroes(int[] nums) {
		int slow = 0; 
		for (int fast = 0; fast < nums.length; ++fast) {
			if (0 != nums[fast]) {
				swap(nums, slow++, fast);
			}
		}
	}

	public static void main(String[] args) {
		int[] nums = { 0, 1, 0, 3, 12 };
		moveZeroes(nums);
		System.out.println(Arrays.toString(nums));
	}
}
