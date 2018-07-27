#include <stdio.h>
#include <stdlib.h>
#include "SortHelp.h"

// 对arr[left...right]部分进行partition操作
// 返回posi,使得arr[left...p-1] < arr[p] ; arr[p+1...right] > arr[p]
int __partition(int *arr, int left, int right)
{
    int i, j;
    int v = arr[left];                      // 基准
    j = left;
    for (i = left + 1; i <= right; ++i)
    {
        // 如果当前元素 比 基准小
        if (arr[i] < v)
        {
            swap(&arr[i], &arr[j + 1]);
            j++;
        }
        // 比基准大 i++
    }
    swap(&arr[left], &arr[j]);
    return j;
}

// 对arr[left, right]进行快速排序
void __QuickSortOneWays(int * arr, int left, int right)
{
    if (left >= right)                          // 递归结束条件
    {
        return;
    }
    int p = __partition(arr, left, right);      // 排好序后 基准所在位置的索引
    __QuickSortOneWays(arr, left, p - 1);              // 对左子序列进行快排
    __QuickSortOneWays(arr, p + 1, right);             // 对右子序列进行快排
}

// 统一接口
void QuickSortOneWays(int * arr, int n)
{
    __QuickSortOneWays(arr, 0, n - 1);
}
