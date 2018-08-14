import java.util.Arrays;

public class Solution1 {
	// ʱ�临�Ӷ�O(N)  �ռ临�Ӷ�O(1)   ˫ָ��
	public static int removeDuplicates(int[] nums) {
		if (nums == null || nums.length == 0) {
			return 0;
		}
		
		int slow = 0;  				 // [0,slow]  ��źϷ�����(��)
		// ��ָ���������  
		for (int fast = 0; fast < nums.length; ++fast) {
			// ��ǰԪ����[0,slow]��δ���֣���ӵ�[0,slow)  �˴�������������������
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
