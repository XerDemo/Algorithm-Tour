#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "SortHelper.h"

// 将arr[left ... right] 进行归并操作
// arr[left,mid]   arr[mid+1, right]各自有序 对其进行归并操作
void __merge1(int *arr, int left, int mid, int right)
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

// 对arr[left ... right] 进行归并排序
void __mergeSort1(int *arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    __mergeSort1(arr, left, mid);           // 对左子序列进行归并排序
    __mergeSort1(arr, mid + 1, right);      // 对右子序列进行归并排序
    __merge1(arr, left, mid , right);       // 将左子序列 右子序列进行归并操作
}

void mergeSort1(int *arr, int n)
{
    __mergeSort1(arr, 0, n - 1);
}

