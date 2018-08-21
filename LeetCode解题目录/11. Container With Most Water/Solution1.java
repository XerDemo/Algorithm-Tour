public class Solution1 {
    // 时间复杂度 O(N^2)   空间复杂度O(1)  暴力破解法
    public int maxArea(int[] height) {
        int res = 0;
        for (int i = 0; i < height.length; ++i) {
            for (int j = i + 1; j < height.length; ++j) {
                int area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
                if (area > res){
                    res = area;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        System.out.println(new Solution1().maxArea(height));
    }
}
