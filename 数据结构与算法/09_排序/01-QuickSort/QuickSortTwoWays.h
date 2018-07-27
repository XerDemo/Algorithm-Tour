#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SortHelp.h"

// ��arr[left...right]���ֽ���partition����
// �����ź���ʱ��׼���ڵ�λ��p,ʹ�� arr[left+1...i) <= v; arr(j...right] >= v
int __partitionTwoWays(int *arr, int left, int right)
{
    int i, j;
    swap(&arr[left], &arr[rand() % (right - left + 1) + left]);   // ѡȡ�����׼ ��arr[left]����
    int v = arr[left];                                            // ��׼ ��ʱ��׼�Ѿ�ʱ�����˵������

    // arr[left+1...i) <= v; arr(j...right] >= v
    i = left + 1, j = right;                                      // i��ʼ��Ϊleft+1 �պ�arr[left+1..i)��Ч jͬ��
    while (1)
    {
        // i ��������ɨ�� �����Ȼ�׼С��Ԫ�� i++
        while (i <= right && arr[i] < v)
        {
            i++;
        }

        // j ��������ɨ�� �����Ȼ�׼���Ԫ�� j--
        while (j >= left + 1 && arr[j] > v)
        {
            j--;
        }

        // ��������ʱ ����֮ǰ�Ķ����߼�  ����ʱ i>j �����ݼ�ͼ�����
        if (i > j)
        {
            break;
        }
        swap(&arr[i], &arr[j]);         // i,j���߶�ӦԪ�ؽ���
        i++;
        j--;
    }
    swap(&arr[left], &arr[j]);          // �ѻ�׼�ŵ� �ź���Ӧ���ڵ�λ��
    return j;
}

// ��arr[left, right]���п�������
void __QuickSortTwoWays(int *arr, int left, int right)
{
    if (right - left <= 15)                      // �ݹ��������
    {
        InsertionSort(arr, left, right);
        return;
    }
    int p = __partitionTwoWays(arr, left, right);      // �ź���� ��׼����λ�õ�����
    __QuickSortTwoWays(arr, left, p - 1);              // ���������н��п���
    __QuickSortTwoWays(arr, p + 1, right);             // ���������н��п���
}

// ͳһ�ӿ�
void QuickSortTwoWays(int *arr, int n)
{
    srand(time(NULL));
    __QuickSortTwoWays(arr, 0, n - 1);
}

