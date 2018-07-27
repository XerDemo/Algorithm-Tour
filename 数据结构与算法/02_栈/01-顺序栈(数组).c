#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10                                       // 顺序栈的最大容量  可用 realloc 扩张
/**
 * 顺序栈(数组)
 * 先进后出   后进先出
 *
 */

typedef struct stack
{
    int data[MAXSIZE];                                   // 定义数组
    int top;                                             // 栈顶指针 指向数组最后一个元素的下标  初始时为空：-1  有一个元素：0 以此类推
} seqStack;

void initSeqStack(seqStack *pS);                        // 初始化方式1：在栈中分配
seqStack *createSeqStack();                             // 初始化方式2：在堆中分配  (此处选用在“堆”中分配)
int emptySeqStack(seqStack *pS);                        // 判断顺序栈 是否为空
int fullSeqStack(seqStack *pS);                         // 判断顺序栈 是否满
int push(seqStack *pS, int val);                        // 入栈
int pop(seqStack *pS, int *pVal);                       // 出栈
int lengthSeqStack(seqStack *pS);                       // 求栈中元素的个数
void traverse(seqStack *pS);                            // 遍历


int main(void)
{
    // 初始化方式1： 使用 声明变量的方式 在（栈）"挖坑"
    seqStack S;
    initSeqStack(&S);

    // 初始话方式2： 使用 malloc  在（堆）  "挖坑"  malloc需要头文件 stdlib.h
    // 在此选用第二种方式
    seqStack *pS = createSeqStack();
    int val;
    printf("length is : %d\n", lengthSeqStack(pS));
    push(pS, 1);
    push(pS, 2);
    push(pS, 3);
    if (pop(pS,&val))
    {
        printf("pop : %d\n", val);
    }
    traverse(pS);
    printf("length is : %d\n", lengthSeqStack(pS));

    return 0;
}

void initSeqStack(seqStack *pS)
{
    pS->top = -1;
}

//创建堆栈 初始化 当top等于-1时 表示栈空    top等于MAXSIZE-1时 表示栈满 
seqStack *createSeqStack()
{
    seqStack *pS = (seqStack *) malloc(sizeof(seqStack));
    if (!pS)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pS->top = -1;
    return pS;
}

int emptySeqStack(seqStack *pS)
{
    return -1 == pS->top;
}

int fullSeqStack(seqStack *pS)
{
    return MAXSIZE - 1 == pS->top;
}
//在执行push操作时，首先看栈是否满 ;若不满则top+1 ，并将新元素放入data数组的top位置 
int push(seqStack *pS, int val)
{
    if (fullSeqStack(pS))
    {
        printf("seqStack is full! push is failed!\n");
        return -1;
    }
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
