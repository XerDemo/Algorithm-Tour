import java.util.Arrays;

public class Solution2 {
    
	// ���ֲ��ҷǵݹ�
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
		return -1;	   // ������ 
	}
	
	// ���ֲ��ҵݹ�
	public static int binarySearch2(int[] numbers, int left, int right, int target) {
		if (left > right) {
			return -1;	// ������
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
	
	// ����õ��Ƕ��ַǵݹ� ʱ�临�Ӷ�O(N*log2^N)   �ռ临�Ӷ�O(1)
	// ����õ��Ƕ��ֵݹ�     ʱ�临�Ӷ�O(N*log2^N)   �ռ临�Ӷ�O(log2^N)
	public static int[] twoSum(int[] numbers, int target) {
		int[] res = new int[2];
		for (int i = 0; i< numbers.length-1; ++i) {
			// j:���ö��ֲ��ҿ�[i+1,nums.length-1] �Ƿ����j���� numbers[i] + numbers[j] == target
			int j = binarySearch2(numbers, i + 1, numbers.length-1, target-numbers[i]);
			if (j != -1) {    // �������
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
