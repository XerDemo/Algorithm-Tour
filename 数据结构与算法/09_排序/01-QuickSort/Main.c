#include <stdio.h>
#include "SortHelp.h"
#include "QuickSortOneWays1.h"
#include "QuickSortTwoWays.h"
#include "QuickSortThreeWays.h"
#include "QuickSortTwoWaysMedian3.h"

int main(void)
{
    // 生成随机数组测试
    int n = 10000000;
    printf("\ntest generateRandomArray, size = %d, random range [0, %d]\n", n, n);
    int *arr1 = generateRandomArray(n, 0, n);    // 生成n个[0,n]的随机数
    int *arr2 = copyArray(arr1, n);
    int *arr3 = copyArray(arr1, n);
    int *arr4 = copyArray(arr1, n);
    testSort(arr1, n, "QuickSortOneWays1", QuickSortOneWays1);
    testSort(arr2, n, "QuickSortTwoWays", QuickSortTwoWays);
    testSort(arr3, n, "QuickSortTwoWaysMedian3", QuickSortTwoWaysMedian3);
    testSort(arr4, n, "QuickSortThreeWays", QuickSortThreeWays);
    free(arr1);free(arr2);free(arr3);free(arr4);

    // 生成 几乎有序的数组 最多只有2*100个元素无序
    int swapTimes = 100;
    printf("\ntest generateNearlyOrderArray, size = %d, sawpTimes = %d\n",n, swapTimes);
    int *arr5 = generateNearlyOrderArray(n, swapTimes);
    int *arr6 = copyArray(arr5, n);
    int *arr7 = copyArray(arr5, n);
    int *arr8 = copyArray(arr5, n);
    testSort(arr5, n, "QuickSortOneWays1", QuickSortOneWays1);
    testSort(arr6, n, "QuickSortTwoWays", QuickSortTwoWays);
    testSort(arr7, n, "QuickSortTwoWaysMedian3", QuickSortTwoWaysMedian3);
    testSort(arr8, n, "QuickSortThreeWays", QuickSortThreeWays);
    free(arr5);free(arr6);free(arr7);free(arr8);

    // 生成大量重复元素数组 [0,10]
    printf("\ntest generateRandomArray, size = %d, random range [0, %d]\n",n, 10);
    int *arr9 = generateRandomArray(n, 0, 10);
    int *arr10 = copyArray(arr9, n);
    int *arr11 = copyArray(arr9, n);
    int *arr12 = copyArray(arr9, n);
    // testSort(arr9, n, "QuickSortOneWays1", QuickSortOneWays1);  // 太慢了 耗时间
    testSort(arr10, n, "QuickSortTwoWays", QuickSortTwoWays);
    testSort(arr11, n, "QuickSortTwoWaysMedian3", QuickSortTwoWaysMedian3);
    testSort(arr12, n, "QuickSortThreeWays", QuickSortThreeWays);
    free(arr9);free(arr10);free(arr11);free(arr12);
    return 0;
}