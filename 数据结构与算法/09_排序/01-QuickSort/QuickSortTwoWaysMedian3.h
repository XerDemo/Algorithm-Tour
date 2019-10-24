// 二路快速排序 基准的选取  三路取中法
#ifndef ALGORITHM_QUICKSORTTWOWAYSMEDIAN3_H
#define ALGORITHM_QUICKSORTTWOWAYSMEDIAN3_H

#include "SortHelp.h"
// 基准的选取采用 三路取中法
int __partitionTwoWaysMedian3(int *arr, int left, int right)
{
    int i, j;

    int mid = left + (right - left) / 2;
    // 这里取三个数排序后，中间那个数作为枢轴
    if (arr[left] > arr[mid])
    {
        swap(&arr[left], &arr[mid]);
    }
    if (arr[left] > arr[right])
    {
        swap(&arr[left], &arr[right]);
    }
    if (arr[mid] > arr[right])
    {
        swap(&arr[mid], &arr[right]);
    }
    /* 此时 arr[left] <= arr[mid] <= arr[right]*/
    swap(&arr[left], &arr[mid]);    // 将基准放到最左边
    int v = arr[left];

    // arr[left+1...i) <= v; arr(j...right] >= v
    i = left + 1, j = right;                                      // i初始化为left+1 刚好arr[left+1..i)无效 j同理
    while (1)
    {
        // i 从左向右扫描 遇到比基准小的元素 i++
        // 注意这里的边界, arr[i] < v, 不能是arr[i] <= v    思考一下为什么?
        while (i <= right && arr[i] < v)
        {
            i++;
        }

        // j 从右向左扫描 遇到比基准大的元素 j--
		// 注意这里的边界, arr[j] > v, 不能是arr[j] >= v 思考？
        while (j >= left + 1 && arr[j] > v)
        {
            j--;
        }

        // 两者相遇时 按照之前的动画逻辑  相遇时 i>j 用数据加图来体会
        if (i > j)
        {
            break;
        }
        swap(&arr[i], &arr[j]);         // i,j两者对应元素交换
        i++;
        j--;
    }
    swap(&arr[left], &arr[j]);          // 把基准放到 排好序应该在的位置 注意是与j交换不是i 画图体会
    return j;
	
/*
	比如数组 1,0,0, ..., 0, 0
	a. 对于arr[i]<v和arr[j]>v的方式，第一次partition得到的分点是数组中间；
	b. 对于arr[i]<=v和arr[j]>=v的方式，第一次partition得到的分点是数组的倒数第二个。
	这是因为对于连续出现相等的情况，a方式会交换i和j的值；而b方式则会将连续出现的这些值归为其中一方，使得两棵子树不平衡
*/
}

// 对arr[left, right]进行快速排序
void __QuickSortTwoWaysMedian3(int *arr, int left, int right)
{
    if (right - left <= 15)                      // 递归结束条件
    {
        InsertionSort(arr, left, right);
        return;
    }
    int p = __partitionTwoWaysMedian3(arr, left, right);      // 排好序后 基准所在位置的索引
    __QuickSortTwoWaysMedian3(arr, left, p - 1);              // 对左子序列进行快排
    __QuickSortTwoWaysMedian3(arr, p + 1, right);             // 对右子序列进行快排
}

// 统一接口
void QuickSortTwoWaysMedian3(int *arr, int n)
{
    srand(time(NULL));
    __QuickSortTwoWays(arr, 0, n - 1);
}
#endif //ALGORITHM_QUICKSORTTWOWAYSMEDIAN3_H
