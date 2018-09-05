import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Solution4 {
    // 时间复杂度O(N) 利用hashMap
    public int[] twoSum(int[] numbers, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] res = new int[2];
        for (int i = 0; i < numbers.length; ++i) {
            if (map.containsKey(target - numbers[i])) {
                res[0] = map.get(target - numbers[i]) + 1;
                res[1] = i + 1;
                break;
            } else {
                map.put(numbers[i], i);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] numbers = {2, 7, 11, 15};
        int target = 9;
        System.out.println(Arrays.toString(new Solution4().twoSum(numbers, target)));
    }
}
