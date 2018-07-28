#ifndef ALGORITHM_SEARCHHELPER_H
#define ALGORITHM_SEARCHHELPER_H
#include <stdio.h>
#include <stdlib.h>
#include "time.h"

// 生成有序的数组  n:数据个数 [0,n)
int * generateOrderArray(int n)
{
    int i;
    int *arr = NULL;
    if (n > 0 )
    {
        arr = (int *) malloc(sizeof(int) * n);
        for (i = 0; i < n; ++i)
        {
            arr[i] = i;
        }
    }
    return arr;
}

// 打印数组内容
void printArray(int * arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

// 测试该算法
void testSearch(char * searchName, int (*search)(int *, int , int ), int * arr, int n )
{
    int i;
    clock_t startTime = clock();
    for (i = 0; i < n; ++i)
    {
        if (i != search(arr, n, i))
        {
            printf("no found %d\n", i);
        }
    }
    clock_t endTime = clock();
    printf("%s test complete.  cost time: %lf s\n", searchName, (double)(endTime - startTime) / CLOCKS_PER_SEC);
}
#endif //ALGORITHM_SEARCHHELPER_H
