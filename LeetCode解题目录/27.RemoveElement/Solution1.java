import java.util.Arrays;

public class Solution1 {
	// ʱ�临�Ӷ� O(N)   �ռ临�Ӷ�O(1)   ˫ָ��
	public static int removeElement(int[] nums, int val) {
		int left = 0;			         // ��Ų�ΪvalԪ�� ����[left, right)
		for (int right = 0; right < nums.length; ++right) {
			if (val != nums[right]) {    
				nums[left++] = nums[right];
			}
		}
		return left;
	}

	public static void main(String[] args) {
		int[] nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
		int val = 2;
		System.out.println(removeElement(nums, val));
		System.out.println(Arrays.toString(nums));
	}
}
