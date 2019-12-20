//#include <iostream>
//#include "SortHelp.h"
//using namespace std;
//
//
//// 调整索引为idx的元素在[idx,end]区间位置  让其符合最大堆的性质
//void shiftDown(int *arr, int idx, int end){
//    int temp = arr[idx];
//    while (idx * 2 + 1 <= end) {  //左孩子 = idx *2 +1 如果在[0,end]中
//        int j = idx * 2 + 1;
//        if (j + 1 <= end && arr[j + 1] > arr[j]) { // 右孩子存在且右孩子比左孩子大
//            j = j + 1;  // 更新j为右孩子的索引
//        }
//        if (temp >= arr[j]) {  //  待调节点 >= 左右孩子最大 满足最大堆性质
//            break;
//        }
//        arr[idx] = arr[j];
//        idx = j;  // 更新待调节点为 左右孩子最大的
//    }
//    arr[idx] = temp;
//}
//
//
//// 原地堆排序
//void HeapSort(int *arr, int n){
//    // heapfiy:将数组堆化
//    for (int i = (n - 2) / 2; i >= 0; --i) {
//        shiftDown(arr, i, n - 1);
//    }
//    for (int j = n - 1; j > 0; --j) {
//        swap(arr[0], arr[j]);
//        shiftDown(arr, 0, j - 1);
//    }
//}
//
//int main(void) {
//    // 生成随机数组测试
//    int n = 1000000;
//    printf("\ntest generateRandomArray, size = %d, random range [0, %d]\n", n, n);
//    int *arr1 = generateRandomArray(n, 0, n);    // 生成n个[0,n]的随机数
//    testSort("HeapSort", HeapSort,arr1, n);
//    return 0;
//}