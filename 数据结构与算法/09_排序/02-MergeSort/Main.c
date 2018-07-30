#include <stdio.h>
#include "SortHelper.h"
#include "MergeSort2.h"
#include "MergeSortBU.h"

int main(void)
{
    int n = pow(10, 8);
    // 测试随机数组
    printf("test generateRandomArray, size = %d, random range [0, %d]\n", n, n);
    int *arr = generateRandomArray(n, 0, n);
    int *arr1 = copyArray(arr, n);
    int *arr2 = copyArray(arr, n);
    int *arr3 = copyArray(arr, n);
    testSort("mergeSort1", mergeSort1, arr, n);
    testSort("mergeSort2", mergeSort2, arr1, n);
    testSort("mergeSortBU", mergeSortBU, arr2, n);
    testSort("mergeSortBU2", mergeSortBU2, arr3, n);
    free(arr);free(arr1);free(arr2);free(arr3);

    // 测试几乎有序的数组
    int swapTimes = 100;
    printf("\ntest generateNearlyOrderArray, size = %d, sawpTimes = %d\n",n, swapTimes);
    int *arr4 = generateNearlyOrderArray(n, swapTimes);
    int *arr5 = copyArray(arr4, n);
    int *arr6 = copyArray(arr4, n);
    int *arr7 = copyArray(arr4, n);
    testSort("mergeSort1", mergeSort1, arr4, n);
    testSort("mergeSort2", mergeSort2, arr5, n);
    testSort("mergeSortBU", mergeSortBU, arr6, n);
    testSort("mergeSortBU2", mergeSortBU2, arr7, n);
    free(arr4);free(arr5);free(arr6);free(arr7);

    // 测试含有大量重复元素的数组  n个数组 范围[0,10]
    printf("\ntest generateRandomArray, size = %d, random range [0, %d]\n",n, 10);
    int *arr8 = generateRandomArray(n, 0, 10);
    int *arr9 = copyArray(arr8, n);
    int *arr10 = copyArray(arr8, n);
    int *arr11 = copyArray(arr8, n);
    testSort("mergeSort1", mergeSort1, arr8, n);
    testSort("mergeSort2", mergeSort2, arr9, n);
    testSort("mergeSortBU", mergeSortBU, arr10, n);
    testSort("mergeSortBU2", mergeSortBU2, arr11, n);
    free(arr8);free(arr9);free(arr10);free(arr11);
    return 0;
}