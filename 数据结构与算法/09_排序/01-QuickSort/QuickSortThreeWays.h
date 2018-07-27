#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortHelp.h"

// arr[left+1...lt] < v  ; arr[lt+1...i-1] == v ; arr[gt...right] >v
void __QuickSortThreeWays(int *arr, int left, int right)
{
    int i, lt, gt;
    if (right - left <= 15)                     // 递归结束条件
    {
        InsertionSort(arr, left, right);
        return;
    }

    swap(&arr[left], &arr[rand() % (right - left + 1) + left]);      // 选取随机基准 与arr[left]交换
    int v = arr[left];                                               // 基准

    lt = left;           // 将初始lt代入 [left+1...lt] < v  刚好使这个区间无效
    gt = right + 1;      // 同理 gt代入  [gt...right] >v
    i = left;            // 同理i代入    [lt+1...i-1] == v

    // i和gt还没遇上
    while (i < gt)
    {
        if (arr[i] < v)               // 当前元素 < 基准
        {
            swap(&arr[i], &arr[lt + 1]);
            lt++;
            i++;
        }
        else if (arr[i] > v)        // 当前元素 > 基准
        {
            swap(&arr[i], &arr[gt - 1]);
            gt--;                     // 注意i不动
        }
        else
        {                             // 等于基准
            i++;
        }
    }
    // 此时i和gt已经遇上了
    swap(&arr[left], &arr[lt]);
    __QuickSortThreeWays(arr, left, lt - 1);  // 交换的时候lt的位置没-1 现在-1
    __QuickSortThreeWays(arr, gt, right);
}


// 统一接口
void QuickSortThreeWays(int *arr, int n)
{
    srand(time(NULL));
    __QuickSortThreeWays(arr, 0, n - 1);
}
