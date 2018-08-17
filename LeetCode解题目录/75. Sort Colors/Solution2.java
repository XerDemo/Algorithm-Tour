import java.util.Arrays;

public class Solution2 {
	public static void swap(int[] nums, int i, int j) {
		int t = nums[i];
		nums[i] = nums[j];
		nums[j] = t;
	}

	public static void insertionSort(int[] nums, int left, int right) {
		for (int i = left + 1; i <= right; ++i) {
			int temp = nums[i];
			int j = i;
			for (; j > left && nums[j - 1] > temp; j--) {
				nums[j] = nums[j-1];
			}
			nums[j] = temp;
		}
	}
    
	
	public static void quickSort3ways(int[] nums, int left, int right) {

		if (right - left <= 15) {
			insertionSort(nums, left, right);
			return;
		}
		// 基准的选取 : 三路取中法
		// 保证nums[left] <= nums[mid] <= nums[right] 最后将nums[left],nums[mid]交换
		int mid = left + (right - left) / 2;
		if (nums[left] > nums[mid]) {
			swap(nums, left, mid);
		}
		if (nums[left] > nums[right]) {
			swap(nums, left, right);
		}
		if (nums[mid] > nums[right]) {
			swap(nums, mid, right);
		}
		swap(nums, left, mid);

		// 基准的选取 : 随机数法
		// swap(nums, left, (int)Math.random() * (right-left+1) + left );
		int v = nums[left];

		int lt = left;
		int gt = right + 1;
		int i = left +1;

		while (i < gt) {
			if (nums[i] == v) {
				i++;
			} else if (nums[i] < v) {
				swap(nums, i++, ++lt);
			} else {
				swap(nums, i, --gt);
			}
		}
		swap(nums, left, lt--);

		quickSort3ways(nums, left, lt);
		quickSort3ways(nums, gt, right);

	}

	public static void sortColors(int[] nums) {
		quickSort3ways(nums, 0, nums.length - 1);
	}

	public static void main(String[] args) {
		int[] nums = { 2, 0, 2, 1, 1, 0 };
		sortColors(nums);
		System.out.println(Arrays.toString(nums));
	}
}
