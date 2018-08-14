import java.util.Arrays;
public class Solution1 {
	// ʱ�临�Ӷ� O(N)   �ռ临�Ӷ�O(1)    ˫ָ��
	public static void moveZeroes(int[] nums) {
		int slow = 0; 		// nums��, [0...slow)��Ԫ�ؾ�Ϊ��0Ԫ��
		for (int fast = 0; fast < nums.length; ++fast) {
			if (0 != nums[fast]) {
				nums[slow++] = nums[fast];
			}
		}
		
		// [slow , nums.length) ���0
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
