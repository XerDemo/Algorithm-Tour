#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void countSort(int * arr, int n)
{
    int max = arr[0], min = arr[0],i;
    // 找出数组中的最大值  最小值
    for (i = 0; i < n; ++i)
    {
        if (arr[i] < min){
            min = arr[i];       // 更新最小值
        }
        if (arr[i] > max) {
            max = arr[i];       // 更新最大值
        }
    }
    int size = max - min + 1;   // 计数数组count的大小

    int *count = (int *) malloc(sizeof(int) * size);
    for (i = 0; i< size;++i)
    {
        count[i] = 0;           // 初始化count
    }

    // 将arr[]对应的数放入统计数组中  arr[i]-min对应的偏移量
    for (i = 0; i< n; ++i)
    {
        count[arr[i] - min]++;
    }

    // 遍历哈希表，将count数组中大于0的数对应出原数组的值，
    int j = 0;
    for (i = 0; i < size; ++i)
    {
        while (count[i]--)
        {
            arr[j++] = i + min;
        }
    }
}

int main(void)
{
    int arr[5] = {3,4,3,2,1};
    countSort(arr,5);
    printArray(arr, 5);
    return 0;
}