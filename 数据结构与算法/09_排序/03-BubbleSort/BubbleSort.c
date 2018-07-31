#include <stdio.h>
#include <stdlib.h>
#include "SortHelper.h"


void bubbleSort1(int *arr, int n)
{
    int p, i;
    for (p = n - 1; p > 0; --p)       // 趟数 n-1趟
    {
        for (i = 0; i < p; ++i)
        {
            // 每趟找出一个最大元素  被交换到最右端
            if (arr[i] > arr[i + 1])  // 若前一个元素大于后一个元素 交换
            {
                swap(&arr[i], &arr[i + 1]);
            }
        }
    }
}

// 优化
void bubbleSort2(int *arr, int n)
{
    int p,i,flag;
    for (p = n - 1; p > 0; --p)       // 趟数 n-1趟
    {
        flag = 1;                     // 1:代表此时整个序列已经有序
        for (i = 0; i < p; ++i)
        {
            // 每趟找出一个最大元素  被交换到最右端
            if (arr[i] > arr[i + 1])  // 若前一个元素大于后一个元素 交换
            {
                swap(&arr[i], &arr[i + 1]);
                flag = 0;             // 说明无序
            }
        }
        if (flag)                     // 如果flag还保持为1 说明已经有序
        {
            break;
        }
    }
}

int main(void)
{
    int n = 100000;
    // 随机数组   区间[0,n]
    printf("test RandomArray size = %d [0,%d]\n", n, n);
    int *arr = generateRandomArray(n, 0, n);
    int *arr1 = copyArray(arr, n);
    testSort("bubbleSort1 ", bubbleSort1, arr, n);
    testSort("bubbleSort2 ", bubbleSort2, arr1, n);

    // 近乎有序的数组 swapTimes：交换次数 区间[0,n)
    int swapTimes = 100;
    printf("\ntest NearlyOrderArray size = %d [0,%d) swapTimes: %d\n", n, n, swapTimes);
    int *arr2 = generateNearlyOrderArray(n, swapTimes);
    int *arr3 = copyArray(arr, n);
    testSort("bubbleSort1 ", bubbleSort1, arr2, n);
    testSort("bubbleSort2 ", bubbleSort2, arr3, n);

    // 近乎倒序的数组  区间[0,n)
    printf("\ntest NearlyReverseArray size = %d [0,%d) swapTimes: %d\n", n, n, swapTimes);
    int *arr4 = generateNearlyReverseOrderArray(n, swapTimes);
    int *arr5 = copyArray(arr4, n);
    testSort("bubbleSort1 ", bubbleSort1, arr4, n);
    testSort("bubbleSort2 ", bubbleSort2, arr5, n);

    // 含大量重复元素的数组  [0,10]
    printf("\ntest RandomArray  size = %d [0,10]\n", n);
    int *arr6 = generateRandomArray(n, 0, 10);
    int *arr7 = copyArray(arr6, n);
    testSort("bubbleSort1 ", bubbleSort1, arr6, n);
    testSort("bubbleSort2 ", bubbleSort2, arr7, n);

    free(arr);free(arr1);free(arr2);free(arr3);free(arr4);free(arr5);free(arr6);free(arr7);
    return 0;
}
