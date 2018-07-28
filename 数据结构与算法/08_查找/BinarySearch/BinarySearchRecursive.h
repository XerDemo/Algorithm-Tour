#include <stdio.h>
#include <math.h>
#include <time.h>
#include "searchHelper.h"

// 定义二分查找的区间为 [left, right]
int __BinarySearchRecursive(int *arr, int left,int right, int target)
{
    if (left > right)      // 根据定义的区间[left, right] 当left == right时 还有效
    {
        return -1;
    }
    int mid = (right - left) / 2 + left;
    if (arr[mid] == target)
    {
        return mid;
    } else if (arr[mid] < target)
    {
        return __BinarySearchRecursive(arr, mid + 1, right,target);
    } else
    {
        return __BinarySearchRecursive(arr, left, mid - 1, target);
    }
}

int BinarySearchRecursive(int *arr, int n, int target)
{
    return  __BinarySearchRecursive(arr, 0, n - 1, target);
}

