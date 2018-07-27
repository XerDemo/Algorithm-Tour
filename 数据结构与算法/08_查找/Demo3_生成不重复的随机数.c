#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
// http://blog.sina.com.cn/s/blog_57de62c00100ltak.html
// 生成不重复的随机数
void swap(int *a, int * b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
int main(void)
{
    int arr[MAXSIZE];
    int i;
    for (i = 0; i < MAXSIZE; ++i)
    {
        arr[i] = i;
    }

    for (i = MAXSIZE - 1; i >= 1; --i)
    {
        swap(&arr[i], &arr[rand() % i]);
//        printf("rand : %d\n", rand());
    }

    for (i = 0; i < MAXSIZE; ++i)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
