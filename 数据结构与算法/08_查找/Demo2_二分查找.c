#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE  10000
/**
 *   二分查找
 *        1.数组
 *        2.有序
 *    时间复杂度 o(log2^n)
 */

int main(void)
{

    clock_t start, finish;
    start = clock();

    int i,left, right, mid,count, val;
    int arr[MAXSIZE];
    // 将数组 从0-99升序初始化
    for (i=0; i<MAXSIZE; ++i)
    {
        arr[i] = i;
    }

    printf("请输入要查找的值：");
    scanf("%d",&val);

    left = 0;
    right = MAXSIZE - 1;
    while (left <= right)
    {
        mid = (left + right)/2;
//        printf("--------------------\n");
//        printf("left: %d\n", left);
//        printf("mid: %d\n", mid);
//        printf("right: %d\n", right);
//        printf("--------------------\n");
        if (arr[mid] < val)
        {
            left = mid + 1;
        } else if (arr[mid] > val)
        {
            right = mid - 1;
        } else{
            break;
        }
    }

    if (left > right)
    {
        printf("该元素未找到！\n");
        printf("共进行%d次比较\n", count);
        printf("可将此数插入到第%d位置上\n",left+1);    // left,mid,right此时指向同一位置  mid+1 right+1 皆可
    } else{
        printf("该元素在数组中的下标为%d\n", mid);
    }

    finish = clock();
    printf("耗时：%fms\n", (double)(finish-start)/CLOCKS_PER_SEC );
    return 0;
}
