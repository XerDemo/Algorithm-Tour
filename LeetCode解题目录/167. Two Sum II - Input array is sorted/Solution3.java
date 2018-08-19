import java.util.Arrays;

public class Solution3 {
    // 时间复杂度O(N)  空间复杂度O(1)  双指针之对撞指针
	public static int[] twoSum(int[] numbers, int target) {
		int i = 0;
		int j = numbers.length-1;
		int[] res = new int[2];
		// 只要i和j没相遇 
		while (i < j) {
			int sum = numbers[i] + numbers[j];
			if (sum > target) {
				j--;
			}else if (sum < target) {
				i++;
			}else {
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
