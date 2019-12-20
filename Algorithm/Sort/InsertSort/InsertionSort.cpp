//#include <stdio.h>
//#include <iostream>
//#include "SortHelper.h"
//using namespace std;
//
////void insertionSort1(int *arr, int n)
////{
////    int i, j;
////    for (i = 1; i < n; ++i)
////    {
//////        for (j = i; j>0; --j)
//////        {
//////            if (arr[j] < arr[j - 1])
//////            {
//////                swap(&arr[j], &arr[j - 1]);
//////            }
//////            else
//////            {
//////                break;
//////            }
//////        }
////        // 可以改写成这样  注意i从1开始 j是>0
////        for (j = i; j > 0 && arr[j] < arr[j - 1]; --j)
////        {
////            swap(&arr[j], &arr[j - 1]);
////        }
////    }
////}
//
//// 优化的直接插入排序  将交换(每次做三步赋值)   换成了 赋值
//void insertionSort(int *arr, int n)
//{
//    int i, j;
//    for (i = 1; i < n; ++i)
//    {
//        int temp = arr[i];        // 取出未排序序列中的第一个元素
//        // 在已排序元素中 从后往前扫描  如果发现比temp大 则往后移一位
//        for (j = i; j > 0 && arr[j-1] > temp; --j)
//        {
//            arr[j] = arr[j-1];
//        }
//        arr[j] = temp;            // temp进入适合的位置
//    }
//}
//
//// 折半插入排序：在直接插入的排序基础上，在已经排好序的表中，用二分查找来找到插入的位置
//void BinaryInsertionSort(int * nums, int n){
//    for (int i = 1; i < n; ++i) {
//        int temp = nums[i];
//        // 开始二分查找 当前元素应该插入的位置
//        int left = 0, right = i-1; // 有序表范围【0，i-1】
//
//        while (left <= right) {
////            cout << "[ " << left << ", " << right << " ]" << endl;
//            int mid = left + (right - left) / 2;
//            if (nums[mid] < temp) { // 去nums[mid]右边查找
//                left = mid + 1;
//            }else{ // nums[mid] == temp
//                right = mid - 1;
//            }
//        }
//
////        cout << "[ " << left << ", " << right << " ]" << endl;
////         此时 right就是要插入的前驱位置
//        for (int j = i-1; j >= right + 1 ; --j) { // 插入位置:right
//            nums[j+1] = nums[j];
//        }
//        nums[right+1] = temp;
//
////        swap(nums[right+1], nums[i]);
//    }
////    cout << "over" << endl;
//}
//
//// 希尔排序：将i，i+d，i+2d....每隔d个增量为一个组，进行直接插入排序
//void shellSort(int * nums, int n){
//    for (int d = n / 2; d >= 1; d = d / 2) { // 增量d 初始d = 表长/2，每次d = d/2 直到d = 1
//        for (int i = d; i < n; ++i) {  // 相当于第一个元素有序
//            if (nums[i] < nums[i - d]) {
//                int temp = nums[i];
//                int j;
//                for (j = i; j >0 && nums[j-d] > temp; j = j - d ) {
//                    nums[j] = nums[j-d];
//                }
//                nums[j] = temp;
//            }
//        }
//    }
//}
//
//int main(void)
//{
//    int n = 100000;
//    // 随机数组   区间[0,n]
//    printf("test RandomArray size = %d [0,%d]\n", n, n);
//    int *arr = generateRandomArray(n, 0, n);
//    int *arr1 = copyArray(arr, n);
//    int *arr2 = copyArray(arr, n);
////    int nums[4] = {11,12,13,12};
//    testSort("insertionSort2 ", insertionSort, arr, n);
////    testSort("BinaryInsertionSort ", BinaryInsertionSort, nums, 4);
//    testSort("BinaryInsertionSort ", BinaryInsertionSort, arr1, n);
//    testSort("shellSort ", shellSort, arr2, n);
//
////
////    // 近乎有序的数组 swapTimes：交换次数 区间[0,n)
////    int swapTimes = 100;
////    printf("\ntest NearlyOrderArray size = %d [0,%d) swapTimes: %d\n", n, n, swapTimes);
////    int *arr2 = generateNearlyOrderArray(n, swapTimes);
////    int *arr3 = copyArray(arr, n);
////    testSort("insertionSort1 ", insertionSort1, arr2, n);
////    testSort("insertionSort2", insertionSort2, arr3, n);
////
////    // 近乎倒序的数组  区间[0,n)
////    printf("\ntest NearlyReverseArray size = %d [0,%d) swapTimes: %d\n", n, n, swapTimes);
////    int *arr4 = generateNearlyReverseOrderArray(n, swapTimes);
////    int *arr5 = copyArray(arr4, n);
////    testSort("insertionSort1 ", insertionSort1, arr4, n);
////    testSort("insertionSort2 ", insertionSort2, arr5, n);
////
////    // 含大量重复元素的数组  [0,10]
////    printf("\ntest RandomArray  size = %d [0,10]\n", n);
////    int *arr6 = generateRandomArray(n, 0, 10);
////    int *arr7 = copyArray(arr6, n);
////    testSort("insertionSort1 ", insertionSort1, arr6, n);
////    testSort("insertionSort2", insertionSort2, arr7, n);
////
////    free(arr);free(arr1);free(arr2);free(arr3);free(arr4);free(arr5);free(arr6);free(arr7);
//    return 0;
//}