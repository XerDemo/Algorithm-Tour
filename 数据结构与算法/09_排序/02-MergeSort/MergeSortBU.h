#include <stdio.h>
#include "MergeSort1.h"
#include "SortHelper.h"

int min(int a, int b)
{
    return a > b ? b : a;
}

void mergeSortBU(int *arr, int n)
{
    int size, i;
    for (size = 1; size <= n; size += size)             // 规模 每次扩大两倍
    {
        for (i = 0; i + size < n; i += 2 * size)
        {
            // 对 arr[i...i+size-1] 和 arr[i+size...i+2*size-1] 进行归并
            // 循环条件i+size < n 是为了确保第二部分的存在 也保证了i+size-1(第一个子序列)不会越界
            // 为了确保第二个子序列不会越界 min(i + 2 * size - 1, n-1)
            __merge1(arr, i, i + size - 1, min(i + 2 * size - 1, n - 1));
        }
    }
}

// 在mergeSortBU的基础上两个地方进行优化
void mergeSortBU2(int *arr, int n)
{
    int size, i;
    // 优化1： 对于小规模数组,使用插入排序
    for (i = 0; i < n; i += 16)
    {
        InsertionSort(arr, i, min(i + 15, n - 1));
    }

    for (size = 16; size <= n; size += size)             // 规模 每次扩大两倍
    {
        for (i = 0; i + size < n; i += 2 * size)
        {
            // 优化2： 对于arr[i + size - 1] > arr[i + size]的情况 不进行merge 因为已经有序
            if (arr[i + size - 1] > arr[i + size])
            {
                __merge1(arr, i, i + size - 1, min(i + 2 * size - 1, n - 1));
            }
        }
    }
}
