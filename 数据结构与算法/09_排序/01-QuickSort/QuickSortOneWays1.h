#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortHelp.h"

// 对arr[left...right]部分进行partition操作
// 返回posi,使得arr[left...p-1] < arr[p] ; arr[p+1...right] > arr[p]
int __partition1(int *arr, int left, int right)
{
    int i, j;
    /******************* 优化2 *******************/
    swap(&arr[left], &arr[rand() % (right - left + 1) + left]);

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
void __QuickSortOneWays1(int * arr, int left, int right)
{
    /************ 优化1 **********/
    if (right - left <= 15)                      // 递归结束条件
    {
        InsertionSort(arr, left, right);
        return;
    }
    int p = __partition1(arr, left, right);      // 排好序后 基准所在位置的索引
    __QuickSortOneWays1(arr, left, p - 1);          // 对左子序列进行快排
    __QuickSortOneWays1(arr, p + 1, right);         // 对右子序列进行快排
}

// 统一接口
void QuickSortOneWays1(int * arr, int n)
{
    srand(time(NULL));
    __QuickSortOneWays1(arr, 0, n - 1);
}
