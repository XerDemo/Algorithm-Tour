
public class Solution1 {

	public static void swap(int[] nums, int i, int j) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
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
	
	public static int parttion(int[] nums, int left, int right) {
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
		int v = nums[left];
		
		int i = left + 1;
		int j = right;
		while (true) {
			while (i<=right && nums[i] < v) {
				i++;
			}
			while (j>=left+1 && nums[j] > v) {
				j--;
			}
			if (i > j) {
				break;
			}
			swap(nums,i++,j--);
		}
		swap(nums, left, j);
		return j;
	}
    // 二路快速排序  
	public static int QuickSort(int[] nums, int left, int right, int k) {
		if (left > right) {
			return Integer.MIN_VALUE;
		}
		int p = parttion(nums, left, right);
		// 发现在基准右边就只快排右边 不管左边 同理
		if (nums.length - k == p) {			// 如果p此时指向的位置就是第K大数
			return nums[p];
		} else if (nums.length - k < p) {	// 如果p此时指向的位置 < 第K大数
			return QuickSort(nums, left, p - 1, k);
		} else {							// 如果p此时指向的位置 > 第K大数
			return QuickSort(nums, p + 1, right, k);
		}
	}

	public static int findKthLargest(int[] nums, int k) {
		return QuickSort(nums, 0, nums.length - 1, k);
	}

	public static void main(String[] args) {
		int[] nums = { 3, 2, 1, 5, 6, 4 };
		int k = 2;
		System.out.println(findKthLargest(nums, k));
	}
}
