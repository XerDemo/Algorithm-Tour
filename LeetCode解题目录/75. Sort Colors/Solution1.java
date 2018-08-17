import java.util.Arrays;

public class Solution1 {
	// 时间复杂度O(N)  空间复杂度O(k) 其中K为要排序的数组的范围 O(3)  计数排序
	public static void sortColors(int[] nums) {
		// 1.创建计数数组  并初始化
		int[] count = new int[3];
		// 2.将nums元素存放进对应的count中计算出现次数
		for (int i=0; i<nums.length; ++i) {
			count[nums[i]]++;
		}
		// 3.根据count出现次数来写入原数组nums
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
