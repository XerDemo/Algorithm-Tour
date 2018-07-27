#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10                                       // 顺序栈的最大容量
#define INCREAMENT 5                                     // 增长因子  每次增长5
/**
 * 顺序栈(数组)
 * 先进后出   后进先出
 *
 */

typedef struct stack
{
    int *data;                                         // 数组空间基址
    int maxsize;                                        // 数组大小
    int top;                                            // 栈顶指针 指向数组最后一个元素的下标  初始时为空：-1  有一个元素：0 以此类推
} seqStack;

seqStack *createSeqStack();                             // 初始化
int emptySeqStack(seqStack *pS);                        // 判断顺序栈 是否为空
int fullSeqStack(seqStack *pS);                         // 判断顺序栈 是否满
int push(seqStack *pS, int val);                        // 入栈
int pop(seqStack *pS, int *pVal);                       // 出栈
int lengthSeqStack(seqStack *pS);                       // 求栈中元素的个数
void traverse(seqStack *pS);                            // 遍历


int main(void)
{
    seqStack *pS = createSeqStack();
    int val;
    printf("length is : %d\n", lengthSeqStack(pS));
    int i;
    for (i = 0; i < 15 ; ++i)
    {
        push(pS,i);
    }
    if (pop(pS, &val))
    {
        printf("pop : %d\n", val);
    }
    traverse(pS);
    printf("length is : %d\n", lengthSeqStack(pS));

    return 0;
}


seqStack *createSeqStack()
{
    seqStack *pS = (seqStack *) malloc(sizeof(seqStack));
    pS->data = (int *) malloc(sizeof(int) * MAXSIZE);
    // 省略 判断 pS  pS->data 为空
    pS->maxsize = MAXSIZE;
    pS->top = -1;
    return pS;
}

int emptySeqStack(seqStack *pS)
{
    return -1 == pS->top;
}

int fullSeqStack(seqStack *pS)
{
    return pS->maxsize - 1 == pS->top;
}

int push(seqStack *pS, int val)
{
    if (fullSeqStack(pS))
    {
        printf("seqStack is full! need to expand space!\n");
        // 临时的数组首地址 pTemp  比之前的空间大 大小为 (pS->maxsize + INCREAMENT) * sizeof(int)
        int *pTemp = (int *) realloc(pS->data, (pS->maxsize + INCREAMENT) * sizeof(int));
        pS->data = pTemp;
        pS->maxsize += INCREAMENT;
    }
    // 这里千万不能加 else 要不然当栈满的时候 只会执行if ,else的不会执行
    pS->data[++pS->top] = val;
    return 1;
}

int pop(seqStack *pS, int *pVal)
{
    if (emptySeqStack(pS))
    {
        printf("seqStack is empty! pop is failed!\n");
        return -1;
    }
    *pVal = pS->data[pS->top--];
    return 1;
}

int lengthSeqStack(seqStack *pS)
{
    return pS->top + 1;
}

void traverse(seqStack *pS)
{
    int i = pS->top;                              // 定义一个变量来接受top 这样遍历之后pS->top的不变  变的是i
    if (emptySeqStack(pS))
    {
        printf("seqStack is empty! traverse is failed!\n");
        return;
    }
    printf("seqStack is : ");
    while (i != -1)
    {
        printf(" %d ", pS->data[i--]);
    }
    printf("\n");
}
