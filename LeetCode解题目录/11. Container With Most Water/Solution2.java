public class Solution2 {
    // 时间复杂度O(N)   空间复杂度O(1)   双指针之对撞指针
    public int maxArea(int[] height) {
        int i = 0;
        int j = height.length - 1;
        int res = 0;
        // 当i,j还未相遇
        while (i < j) {
            int area = (j - i) * Math.min(height[i], height[j]);  //  计算当前所围面积
            if (height[i] < height[j]){                // 如果是height[i]小了 尝试i++
                i++;
            }else {                                    // 如果是height[j]小了 尝试j--
                j--;
            }
            if (res < area) {
                res = area;                             // 更新所围最大面积
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        System.out.println(new Solution2().maxArea(height));
    }
}
