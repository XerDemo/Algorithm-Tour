#include <stdio.h>
#include "SortHelp.h"
#include "QuickSortOneWays1.h"
#include "QuickSortTwoWays.h"
#include "QuickSortThreeWays.h"

int main(void)
{
    // 生成随机数组测试
    int n = 10000000;
    printf("\ntest generateRandomArray, size = %d, random range [0, %d]\n ", n, n);
    int *arr1 = generateRandomArray(n, 0, n);    // 生成n个[0,n]的随机数
    int *arr2 = copyArray(arr1, n);
    int *arr3 = copyArray(arr2, n);
    testSort(arr1, n, "QuickSortOneWays1", QuickSortOneWays1);
    testSort(arr2, n, "QuickSortTwoWays", QuickSortTwoWays);
    testSort(arr3, n, "QuickSortThreeWays", QuickSortThreeWays);
    free(arr1);
    free(arr2);
    free(arr3);

    // 生成 几乎有序的数组 最多只有2*100个元素无序
    int swapTimes = 100;
    printf("\ntest generateNearlyOrderArray, size = %d, sawpTimes = %d\n",n, swapTimes);
    int *arr4 = generateNearlyOrderArray(n, swapTimes);
    int *arr5 = copyArray(arr4, n);
    int *arr6 = copyArray(arr4, n);
    testSort(arr4, n, "QuickSortOneWays1", QuickSortOneWays1);
    testSort(arr5, n, "QuickSortTwoWays", QuickSortTwoWays);
    testSort(arr6, n, "QuickSortThreeWays", QuickSortThreeWays);
    free(arr4);
    free(arr5);
    free(arr6);

    // 生成大量重复元素数组 [0,10]
    printf("\ntest generateRandomArray, size = %d, random range [0, %d]\n",n, 10);
    int *arr7 = generateRandomArray(n, 0, 10);
    int *arr8 = copyArray(arr7, n);
    int *arr9 = copyArray(arr7, n);
//    testSort(arr7, n, "QuickSortOneWays1", QuickSortOneWays1);
    testSort(arr8, n, "QuickSortTwoWays", QuickSortTwoWays);
    testSort(arr9, n, "QuickSortThreeWays", QuickSortThreeWays);
    free(arr7);
    free(arr8);
    free(arr9);
    return 0;
}