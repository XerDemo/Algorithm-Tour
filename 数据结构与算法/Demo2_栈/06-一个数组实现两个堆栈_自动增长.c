#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5                                          // 数组初始最大容量
#define INCREATEMENT 5                                     // 增长因子  用realloc 实现对数组空间进行扩增 每次扩大5个

/**
 * 一个数组实现堆栈 自动增长
 * flag == 1 对 pTop1所在堆栈进行操作  flag == 2 对 pTop2所在堆栈进行操作
 */
typedef struct
{
    char * data;                                            // 字符数组
    int maxsize;                                            // 最大容量
    int pTop1;                                              // pTop1 栈顶指针
    int pTop2;                                              // pTop2 栈顶指针
}seqStack;

seqStack * createStack();                                   // 对栈进行初始化
void push(seqStack *pS, int val, int flag);                 // 入栈
int pop(seqStack *pS,  int flag);                           // 出栈
void traverse(seqStack *pS, int flag);                      // 遍历
int lengthStack(seqStack * pS, int flag);                   // 求栈内元素

int main(void)
{
    seqStack * pS =createStack();
    push(pS, 1, 1);
    push(pS, 2, 1);
    push(pS, 3, 1);
    push(pS, 4, 1);
    push(pS, 5, 1);
    push(pS, 6, 1);
    push(pS, 7, 1);
    pop(pS,1);
    push(pS, 8, 1);

    push(pS, 5, 2);
    push(pS, 6, 2);
    push(pS, 7, 2);
    push(pS, 8, 2);
    push(pS, 9, 2);
    push(pS, 10, 2);


    traverse(pS, 1);
    traverse(pS, 2);
    printf("pTop1 所在堆栈长度：%d\n",lengthStack(pS,1));
    printf("pTop2 所在堆栈长度：%d\n",lengthStack(pS,2));

    return 0;
}

// 初始化
seqStack * createStack()
{
    seqStack *pS = (seqStack *) malloc(sizeof(seqStack));
    pS->data = (char * )malloc(sizeof(char) * MAXSIZE);
    if (!pS || !pS->data)
    {
        printf("malloc is failed\n");
        exit(-1);
    }
    pS->pTop1 = -1;
    pS->maxsize = MAXSIZE;
    pS->pTop2 = pS->maxsize;

    return pS;
}
// 入栈
void push(seqStack *pS, int val, int flag)
{
    // 如果栈满
    if (1 == pS->pTop2 - pS->pTop1)
    {
        // realloc申请更多的空间
        char *pTemp = (char *) realloc(pS->data, sizeof(char) * (pS->maxsize + INCREATEMENT));
        if (!pTemp)
        {
            printf("malloc is failed\n");
            exit(-1);
        }
        // 将申请的空间赋给pS->data
        pS->data = pTemp;
        // 数组的最大长度 更新
        pS->maxsize += INCREATEMENT;

        // 同时pTop2栈内的元素移到新增数组空间对应的位置， pTop1不需要移动 画图就知道了
        int i, k;      // i：未增长空间时，pTop2的索引   k：pTop栈内元素个数
        for (i = pS->pTop2, k = 0; k < lengthStack(pS, 2); ++i, ++k)
        {
            //i + INCREATEMENT： 增长INCREATEMENT空间后对应的pS->pTop2的索引
            pS->data[i + INCREATEMENT] = pS->data[i];
        }
        // 更新pTop2的位置
        pS->pTop2 += INCREATEMENT;

    }

    if (flag == 1)
    {
        pS->data[++pS->pTop1] = val;
    }
    else
    {
        pS->data[--pS->pTop2] = val;
    }
}

int pop(seqStack *pS, int flag)
{
    if (flag == 1)
    {
        if (-1 == pS->pTop1)
        {
            printf("pTop1 所在栈 空！\n");
            return -1;
        }
        else
        {
            return pS->data[pS->pTop1--];
        }
    }
    else
    {
        if (pS->maxsize == pS->pTop2)
        {
            printf("pTop2 所在栈 空！\n");
            return -1;
        }
        else
        {
            return pS->data[pS->pTop2++];
        }
    }
}

int lengthStack(seqStack * pS, int flag)
{
    if (flag == 1)
    {
        return pS->pTop1 + 1;
    }
    else
    {
        return pS->maxsize - pS->pTop2;
    }
}

void traverse(seqStack *pS, int flag)
{
    if (flag == 1)
    {
        int i = pS->pTop1;
        if (-1 == pS->pTop1)
        {
            printf("pTop1 所在栈 空\n");
            return ;
        }
        printf("pTop1 栈 : ");
        while (-1 != i)
        {
            printf(" %d ", pS->data[i--]);
        }
        printf("\n");
    }
    else
    {

        if (pS->maxsize == pS->pTop2)
        {
            printf("pTop2 所在栈 空！\n");
            return ;
        }

        int i = pS->pTop2;
        printf("pTop2 栈 : ");
        while (pS->maxsize != i)
        {
            printf(" %d ", pS->data[i++]);
        }
        printf("\n");
    }
}
