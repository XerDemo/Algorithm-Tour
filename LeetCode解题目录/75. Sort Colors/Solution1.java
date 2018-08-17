import java.util.Arrays;

public class Solution1 {
	// ʱ�临�Ӷ�O(N)  �ռ临�Ӷ�O(k) ����KΪҪ���������ķ�Χ O(3)  ��������
	public static void sortColors(int[] nums) {
		// 1.������������  ����ʼ��
		int[] count = new int[3];
		// 2.��numsԪ�ش�Ž���Ӧ��count�м�����ִ���
		for (int i=0; i<nums.length; ++i) {
			count[nums[i]]++;
		}
		// 3.����count���ִ�����д��ԭ����nums
		int j = 0;
		for (int i=0; i<count.length; ++i) {
			while (count[i]-- != 0) {
				nums[j++] = i;
			}
		}
	}

	public static void main(String[] args) {
		int[] nums = { 2, 0, 2, 1, 1, 0 };
		sortColors(nums);
		System.out.println(Arrays.toString(nums));
	}
}
