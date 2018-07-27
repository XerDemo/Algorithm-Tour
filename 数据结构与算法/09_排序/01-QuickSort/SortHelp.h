
#ifndef ALGORITHM_SORTHELP_H
#define ALGORITHM_SORTHELP_H
#include <stdlib.h>
#include <time.h>

// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR] 左闭右闭区间
int * generateRandomArray(int n, int rangeL, int rangeR)
{
    int i;
    int *arr = NULL;
    if (n > 0 && rangeR >= rangeL)
    {
        arr = (int *) malloc(sizeof(int) * n);   // 用malloc 分配数组 是因为不用malloc的话 随着此函数的结束 数组空间会被释放掉
        srand(time(NULL));                       // 设置随机种子
        for (i = 0; i < n; ++i)
        {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;  // 注意随机数所在区间区间是[rangeL, rangeR]
        }
    }
    return arr;
}

// 交换两个数
void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 生成近乎有序的数组  n:数据个数  swapTimes:交换次数  最多只有2*交换次数个元素无序
int * generateNearlyOrderArray(int n, int swapTimes)
{
    int i;
    int *arr = NULL;
    if (n > 0 && swapTimes >= 0)
    {
        arr = (int *) malloc(sizeof(int) * n);
        srand(time(NULL));

        for (i = 0; i < n; ++i)
        {
            arr[i] = i;
        }

        for (i = 0; i < swapTimes; ++i)
        {
            int x = rand() % n;
            int y = rand() % n;
            swap(&arr[x], &arr[y]);
        }
    }
    return arr;
}

// 测试此排序方法 第四个形参传递的是方法
void testSort(int * arr, int n, char * sortName , void(*sort)(int * , int ))
{
    clock_t startTime = clock();
    sort(arr, n);
    clock_t endTime = clock();
    printf("%s cost time: %lf s\n", sortName, (double) (endTime - startTime) / CLOCKS_PER_SEC);
}

// 复制数组
int * copyArray(int * arr, int n)
{
    int i;
    int *newArr = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; ++i)
    {
        newArr[i] = arr[i];
    }
    return newArr;
}

// 插入排序
void InsertionSort(int * arr, int left, int right)
{
    int i, j;
    for (i = left + 1; i <= right; ++i)
    {
        int temp = arr[i];
        for (j = i; j > left && arr[j-1] > temp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
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
#endif //ALGORITHM_SORTHELP_H
