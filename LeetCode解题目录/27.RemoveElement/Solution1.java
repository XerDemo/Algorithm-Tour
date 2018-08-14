import java.util.Arrays;

public class Solution1 {
	// 时间复杂度 O(N)   空间复杂度O(1)   双指针
	public static int removeElement(int[] nums, int val) {
		int slow = 0;			         // 存放不为val元素 区间[0, slow)
		for (int fast = 0; fast < nums.length; ++fast) {
			if (val != nums[fast]) {    
				nums[slow++] = nums[fast];
			}
		}
		return slow;
	}

	public static void main(String[] args) {
		int[] nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
		int val = 2;
		System.out.println(removeElement(nums, val));
		System.out.println(Arrays.toString(nums));
	}
}
