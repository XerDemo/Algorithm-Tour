//#include <iostream>
//#include "SortHelp.h"
//using namespace std;
//
//// 双向冒泡：奇数趟，从前往后比较相邻元素，关键字最大的放在序列尾
////         偶数趟，从后往前比较相邻元素，关键字最小的放在序列头
//void BubbleSort(int * nums, int n){
//    int left = 0, right = n - 1; // [left,right]排序
//    while (left < right) {
//        bool flag = true; // 默认为true表示有序，如果flag在冒泡过程中没有改变，说明已经有序
//        // 奇数趟：从左到右冒泡 将关键字大的放到序列尾
//        for (int i = left; i < right; ++i) {
//            if (nums[i] > nums[i + 1]) {
//                swap(nums[i], nums[i + 1]);
//                flag = false;
//            }
//        }
//        right--; // 更新
//        // 偶数趟：从右到左冒泡 将关键字小的放到序列头
//        for (int i = right; i > left; --i) {
//            if (nums[i] < nums[i - 1]) {
//                swap(nums[i], nums[i - 1]);
//                flag = false;
//            }
//        }
//        left++; // 更新
//        if (flag == true) { // 说明已经有序
//            return;
//        }
//    }
//}
//
//int main(void) {
//    int n = 100;
//    // 随机数组   区间[0,n]
////    printf("test RandomArray size = %d [0,%d]\n", n, n);
//    int *nums = generateRandomArray(n, 0, n);
//    printArray(nums, n);
//    testSort("BubbleSort ", BubbleSort, nums, n);
//    printArray(nums, n);
//    return 0;
//}