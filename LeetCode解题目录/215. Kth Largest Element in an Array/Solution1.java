
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
		// ��׼��ѡȡ : ��·ȡ�з�
		// ��֤nums[left] <= nums[mid] <= nums[right] ���nums[left],nums[mid]����
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
    // ��·��������  
	public static int QuickSort(int[] nums, int left, int right, int k) {
		if (left > right) {
			return Integer.MIN_VALUE;
		}
		int p = parttion(nums, left, right);
		// �����ڻ�׼�ұ߾�ֻ�����ұ� ������� ͬ��
		if (nums.length - k == p) {			// ���p��ʱָ���λ�þ��ǵ�K����
			return nums[p];
		} else if (nums.length - k < p) {	// ���p��ʱָ���λ�� < ��K����
			return QuickSort(nums, left, p - 1, k);
		} else {							// ���p��ʱָ���λ�� > ��K����
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
