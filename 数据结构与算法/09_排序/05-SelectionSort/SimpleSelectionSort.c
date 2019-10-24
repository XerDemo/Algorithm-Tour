#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "SortHelper.h"

// 时间复杂度 O(n^2)   空间复杂度O(1):只声明了i，j，minIndex等变量
void selectionSort(int * arr, int n)
{
    int i, j;
    for (i = 0; i < n; ++i)      // n-1趟
    {
        int minIndex = i;
        for (j = i+1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex]) { 
				minIndex = j; // 更新
			}
        }
		if (minIndex != i) {
			swap(arr[minIndex], arr[i]);
		}
    }
}

int main(void)
{
    int n = pow(10, 5);
    int *arr = generateRandomArray(n, 0, n);
    int *arr1 = generateNearlyOrderArray(n, 100);
    int *arr2 = generateRandomArray(n, 0, 10);
    testSort("simple seletion sort RandomArray", selectionSort, arr, n);
    testSort("simple seletion sort NearlyOrderArray", selectionSort, arr1, n);
    testSort("simple seletion sort RandomArray [0,10]", selectionSort, arr2, n);

    return 0;
}