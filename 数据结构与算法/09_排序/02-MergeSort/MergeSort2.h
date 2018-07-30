#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SortHelper.h"

// 将arr[left ... right] 进行归并操作
void __merge2(int *arr, int left, int mid, int right)
{
    int i, j, k;
    int aux[right - left + 1];              // 辅助数组aux[]  复制即将整合的两个序列
    for (i = left; i <= right; ++i)
    {
        aux[i - left] = arr[i];             // aux[] 复制 arr[]的内容
    }

    i = left, j = mid + 1;                  // i指向第一个序列的起始位置  j指向第二个序列的起始位置

    for (k = left; k <= right; ++k)
    {
        if (i > mid)                        // 如果第一个序列结束  将第二个序列搬到arr[]
        {
            arr[k] = aux[j - left];
            j++;
        }
        else if (j > right)                 // 如果第二个序列结束  将第一个序列搬到arr[]
        {
            arr[k] = aux[i-left];
            i++;
        }
        else if (aux[i-left] < aux[j-left])  // 如果此时i指向的元素 小于 j
        {
            arr[k] = aux[i - left];
            i++;
        }
        else{
            arr[k] = aux[j - left];
            j++;
        }
    }
}

// 在__mergeSort1的基础上两个地方进行优化
// 对arr[left ... right] 进行归并排序
void __mergeSort2(int *arr, int left, int right)
{
    // 优化1： 对于小规模数组,使用插入排序
    if (right - left <= 15)
    {
        InsertionSort(arr, left, right);
        return;
    }
    int mid = left + (right - left) / 2;
    __mergeSort2(arr, left, mid);
    __mergeSort2(arr, mid + 1, right);
    // 优化2： 对于arr[mid] <= arr[mid+1]的情况 不进行merge 因为已经有序
    // 对于近乎有序的数组非常有效 但是对于一般情况，有一定的性能损失（判读需要时间）
    if (arr[mid] > arr[mid + 1])
    {
        __merge2(arr, left, mid , right);
    }

}

void mergeSort2(int *arr, int n)
{
    __mergeSort2(arr, 0, n - 1);
}

