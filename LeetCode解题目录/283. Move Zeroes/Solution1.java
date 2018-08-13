import java.util.Arrays;
public class Solution1 {
	// ʱ�临�Ӷ� O(N)   �ռ临�Ӷ�O(1)    ˫ָ��
	public static void moveZeroes(int[] nums) {
		int left = 0; 		// [left,right) ��� ����Ԫ��
		for (int right = 0; right < nums.length; ++right) {
			if (0 != nums[right]) {
				nums[left++] = nums[right];
			}
		}
		
		// [right , nums.length) ���0
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
