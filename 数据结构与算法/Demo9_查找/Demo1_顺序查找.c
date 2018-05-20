#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100000000                      // 开辟数组空间最大容量
/*
顺序查找既适用于顺序表，也适用于链表。   时间复杂度 o(n) 

基本思想：从表的一端开始，顺序扫描线性表，依次按给定的值与关键字（key）做比较，若相等则比较成功，并给出数据元素在线性表中的位置；
         若整个线性表查找完毕，仍未找到与给定值相同的关键字，则查找失败，给出失败信息。

数据元素从下标为1的数组单元开始存放，0号单元作为监测哨，用来存放待查找的值。

适用于：当查找的数据元素对象结合中元素的数量N不大的时候可以采用"顺序查找" 
 */

double seqFindMinitor();                       // 带哨兵
double seqFind();                              // 不带哨兵

int main(void)
{

    int i;
    double sum = 0;

//    for (i = 0; i < 20; ++i)
//    {
//        sum += seqFindMinitor();
//    }
//    printf("带哨兵总共花费：%f s\n", sum);
//    printf("带哨兵平均花费：%f s\n", sum / 30);


    for (i = 0; i < 20; ++i)
    {
        sum += seqFind();
    }
    printf("不带哨兵总共花费：%f s\n", sum);
    printf("不带哨兵平均花费：%f s\n", sum / 30);

    return 0;
}

// 不带监测哨
double seqFind()
{
    clock_t start, finish;
    start = clock();

    long *data = (long *) malloc(sizeof(long) * MAXSIZE);
    long key = 2;                                 // 待查找的关键字
    long i;
    // 将data数组初始化
    for (i = 0; i < MAXSIZE; ++i)
    {
        data[i] = i;
    }

    // 开始查找  这里我从后往前查
    for (i = MAXSIZE - 1; i >= 0; --i)          // 时间复杂度 o(n) 
    {
        if (key == data[i])
        {
            printf("key = %ld 在data数组中的index： %ld\n", key, i);
            break;
        }
    }

    finish = clock();
//    printf("不带哨兵Time：%f s\n", (double) (finish - start) / CLOCKS_PER_SEC);
    return (double) (finish - start) / CLOCKS_PER_SEC;
}

// 带监测哨
double seqFindMinitor()
{
    clock_t start, finish;
    start = clock();

    long *data = (long *) malloc(sizeof(long) * MAXSIZE);
    long key = 2;                                 // 待查找的关键字
    long i;
    // 将data数组初始化
    for (i = 0; i < MAXSIZE; ++i)             
    {
        data[i] = i;
    }

    /****************************************************************/
    // 开始查找  这里我从后往前查
    data[0] = key;
    // 与不带哨兵相比 这里少了一个判断条件i>=0  加快了速度
    for (i = MAXSIZE - 1; key != data[i]; --i);   // 时间复杂度 o(n) 
    // for循环结束 则此时key == data[i]  如果i==0 说明没找到
    if (i == 0)
    {
        printf("no found!\n");
    } else
    {
        printf("key = %ld 在data数组中的index： %ld\n", key, i);
    }
    /*****************************************************************/
    finish = clock();
//    printf("带哨兵Time：%f s\n", (double) (finish - start) / CLOCKS_PER_SEC);
    return (double) (finish - start) / CLOCKS_PER_SEC;
}




