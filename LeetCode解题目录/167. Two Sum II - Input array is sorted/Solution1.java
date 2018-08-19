import java.util.Arrays;

public class Solution1 {
    // 时间复杂度O(N^2)  空间复杂度O(1)   暴力枚举法
	public static int[] twoSum(int[] numbers, int target) {
		int[] res = new int[2];			
		// 双重循环遍历i和i之后的元素是否满足相加等于target
		for (int i = 0; i < numbers.length; ++i) {
			for (int j = i + 1; j < numbers.length; ++j) {
				// 如果满足条件  加入res中
				if (numbers[i] + numbers[j] == target) {
					res[0] = i + 1;
					res[1] = j + 1;
					return res;
				}
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
