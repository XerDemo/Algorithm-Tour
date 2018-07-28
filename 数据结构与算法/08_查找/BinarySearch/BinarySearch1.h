#include <stdio.h>
#include <math.h>
#include <time.h>
#include "searchHelper.h"


// 定义二分查找的区间为 [left, right]
int binarySearch1(int *arr, int n, int target)
{
    int left = 0, right = n - 1;     // 在[left...right]的范围里寻找target
    while (left <= right)            // 当 left == right时,区间[left...right]依然是有效的
    {
        // int mid = (left + right) / 2;  此写法有bug 如果left + right超出了整数的范围 数据溢出
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        } else if (arr[mid] > target)
        {
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    return -1;    // 找不到
}


