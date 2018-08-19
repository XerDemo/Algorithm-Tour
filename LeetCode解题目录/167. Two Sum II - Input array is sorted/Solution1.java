import java.util.Arrays;

public class Solution1 {
    // ʱ�临�Ӷ�O(N^2)  �ռ临�Ӷ�O(1)   ����ö�ٷ�
	public static int[] twoSum(int[] numbers, int target) {
		int[] res = new int[2];			
		// ˫��ѭ������i��i֮���Ԫ���Ƿ�������ӵ���target
		for (int i = 0; i < numbers.length; ++i) {
			for (int j = i + 1; j < numbers.length; ++j) {
				// �����������  ����res��
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
