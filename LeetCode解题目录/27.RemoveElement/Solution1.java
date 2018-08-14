import java.util.Arrays;

public class Solution1 {
	// ʱ�临�Ӷ� O(N)   �ռ临�Ӷ�O(1)   ˫ָ��
	public static int removeElement(int[] nums, int val) {
		int slow = 0;			         // ��Ų�ΪvalԪ�� ����[0, slow)
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
