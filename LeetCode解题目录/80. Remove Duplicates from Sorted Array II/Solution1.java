import java.util.Arrays;

public class Solution1 {
	public static int removeDuplicates(int[] nums) {
		if (nums == null || nums.length == 0) {
			return 0;
		}
		
		int slow = 0;		// [0,slow] ´æ·Åanswer
		int count = 1;				
		for (int fast = 1; fast < nums.length; ++fast) {
			if (nums[slow] == nums[fast]) {
				if (count < 2) {
					nums[++slow] = nums[fast];
					count++;
				}
			}else {
				nums[++slow] = nums[fast];
				count = 1;
			}
		}
		return slow + 1;
	}

	public static void main(String[] args) {
		int[] nums = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
		System.out.println(removeDuplicates(nums));
		System.out.println(Arrays.toString(nums));
	}
}
