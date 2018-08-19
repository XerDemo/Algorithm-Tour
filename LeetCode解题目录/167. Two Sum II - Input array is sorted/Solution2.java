import java.util.Arrays;

public class Solution2 {
    
	// 二分查找非递归
	public static int binarySearch(int[] numbers, int left, int right, int target) {
		while (left <= right) {
			int mid = left + (right - left)/2;
			if (target > numbers[mid]) {
				left = mid + 1;
			}else if (target < numbers[mid]) {
				right = mid -1;
			}else {
				return mid;
			}
		}
		return -1;	   // 不存在 
	}
	
	// 二分查找递归
	public static int binarySearch2(int[] numbers, int left, int right, int target) {
		if (left > right) {
			return -1;	// 不存在
		}
		int mid =  (right-left)/2 + left;
		if (target > numbers[mid]) {
			return binarySearch2(numbers, mid + 1, right, target);
		}else if (target < numbers[mid]) {
			return binarySearch2(numbers, left, mid-1, target);
		}else {
			return mid;
		}
	}
	
	// 如果用的是二分非递归 时间复杂度O(N*log2^N)   空间复杂度O(1)
	// 如果用的是二分递归     时间复杂度O(N*log2^N)   空间复杂度O(log2^N)
	public static int[] twoSum(int[] numbers, int target) {
		int[] res = new int[2];
		for (int i = 0; i< numbers.length-1; ++i) {
			// j:利用二分查找看[i+1,nums.length-1] 是否存在j满足 numbers[i] + numbers[j] == target
			int j = binarySearch2(numbers, i + 1, numbers.length-1, target-numbers[i]);
			if (j != -1) {    // 如果存在
				res[0] = i+1;
				res[1] = j+1;
				break;
			}
		}
		return res;
	}

	public static void main(String[] args) {
		int[] numbers = { 2, 7, 11, 15 };
		int target = 9;
		System.out.println(Arrays.toString(twoSum(numbers, target)));
	}
}
