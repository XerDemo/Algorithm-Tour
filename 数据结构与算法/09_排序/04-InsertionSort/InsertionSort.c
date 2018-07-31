#include <stdio.h>
#include "SortHelper.h"

void insertionSort1(int *arr, int n)
{
    int i, j;
    for (i = 1; i < n; ++i)
    {
//        for (j = i; j>0; --j)
//        {
//            if (arr[j] < arr[j - 1])
//            {
//                swap(&arr[j], &arr[j - 1]);
//            }
//            else
//            {
//                break;
//            }
//        }
        // 可以改写成这样  注意i从1开始 j是>0
        for (j = i; j > 0 && arr[j] < arr[j - 1]; --j)
        {
            swap(&arr[j], &arr[j - 1]);
        }
    }
}

// 优化的插入排序  将交换(每次做三步赋值)   换成了 赋值
void insertionSort2(int *arr, int n)
{
    int i, j;
    for (i = 1; i < n; ++i)
    {
        int temp = arr[i];        // 取出未排序序列中的第一个元素
        // 在已排序元素中 从后往前扫描  如果发现比temp大 则往后移一位
        for (j = i; j > 0 && arr[j-1] > temp; --j)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;            // temp进入适合的位置
    }
}

int main(void)
{
    int n = 100000;
    // 随机数组   区间[0,n]
    printf("test RandomArray size = %d [0,%d]\n", n, n);
    int *arr = generateRandomArray(n, 0, n);
    int *arr1 = copyArray(arr, n);
    testSort("insertionSort1", insertionSort1, arr, n);
    testSort("insertionSort2 ", insertionSort2, arr1, n);


    // 近乎有序的数组 swapTimes：交换次数 区间[0,n)
    int swapTimes = 100;
    printf("\ntest NearlyOrderArray size = %d [0,%d) swapTimes: %d\n", n, n, swapTimes);
    int *arr2 = generateNearlyOrderArray(n, swapTimes);
    int *arr3 = copyArray(arr, n);
    testSort("insertionSort1 ", insertionSort1, arr2, n);
    testSort("insertionSort2", insertionSort2, arr3, n);

    // 近乎倒序的数组  区间[0,n)
    printf("\ntest NearlyReverseArray size = %d [0,%d) swapTimes: %d\n", n, n, swapTimes);
    int *arr4 = generateNearlyReverseOrderArray(n, swapTimes);
    int *arr5 = copyArray(arr4, n);
    testSort("insertionSort1 ", insertionSort1, arr4, n);
    testSort("insertionSort2 ", insertionSort2, arr5, n);

    // 含大量重复元素的数组  [0,10]
    printf("\ntest RandomArray  size = %d [0,10]\n", n);
    int *arr6 = generateRandomArray(n, 0, 10);
    int *arr7 = copyArray(arr6, n);
    testSort("insertionSort1 ", insertionSort1, arr6, n);
    testSort("insertionSort2", insertionSort2, arr7, n);

    free(arr);free(arr1);free(arr2);free(arr3);free(arr4);free(arr5);free(arr6);free(arr7);
    return 0;
}