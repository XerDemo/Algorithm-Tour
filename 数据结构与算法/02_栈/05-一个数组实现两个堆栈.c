<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5                                 // 最大容量  如果不够可以用realloc
/**
 * 一个数组  实现两个堆栈
 * 解决：这两个栈分别从数组的两头开始向中间生长；当两个栈的栈顶指针相遇时，表示两个栈都满了
 */

typedef struct
{
    int data[MAXSIZE];                              // 定义数组 如果想要自定增长的话 可以写成 int *data; int maxSize; 配上realloc来自动增长
    int pTop1;                                      // 堆栈1 的栈顶指针
    int pTop2;                                      // 堆栈2 的栈顶指针
}Stack;

Stack * createStack();                              // 创建栈
int fullStack(Stack *pS);                           // 判断满   这里不需要 flag
int emptyStack(Stack *pS, int flag);                // 判断堆栈1 堆栈2 是否为空
int push(Stack *pS, int val, int flag);             // 入栈
int pop(Stack *pS, int *pVal, int flag);            // 出栈
void traverse(Stack *pS, int flag);                 // 遍历
int lengthStack(Stack *pS, int flag);               // 求 堆栈1或2的元素个数

// flag == 1 表示对 堆栈1 操作  pTop1
// flag != 1 表示对 堆栈2 操作  pTop2
int main(void)
{
    int val;
    // 用malloc 的方式 （堆） 来创建栈
    Stack * pS = createStack();
    // 对堆栈1进行操作
    printf("pTop1 length : %d\n",lengthStack(pS,1));
    printf("pTop2 length : %d\n",lengthStack(pS,2));

    push(pS,1,1);
    push(pS,2,1);
    if (pop(pS,&val,1))
    {
        printf("pTop1 pop is : %d\n", val);
    }
    push(pS,3,1);

    traverse(pS,1);
    traverse(pS,2);
    printf("pTop1 length : %d\n",lengthStack(pS,1));
    printf("pTop2 length : %d\n",lengthStack(pS,2));

    // 对堆栈2进行操作
    push(pS,10,2);
    if (pop(pS,&val,2))
    {
        printf("pTop2 pop is : %d\n", val);
    }
    push(pS,11,2);
    push(pS,99,2);
    printf("pTop1 length : %d\n",lengthStack(pS,1));
    printf("pTop2 length : %d\n",lengthStack(pS,2));
    traverse(pS,1);
    traverse(pS,2);

}

// 初始化 pTop1 = -1   pTop2 = MAXSIZE
Stack * createStack()
{
    Stack *pS = (Stack *)malloc(sizeof(Stack));
    if (NULL == pS)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pS->pTop1 = -1;
    pS->pTop2 = MAXSIZE;
}

// 判断满 当两个栈的栈顶指针相遇时，表示两个栈都满了 pS->Top1 + 1 = pS->pTop2
int fullStack(Stack *pS)
{
    return 1 == pS->pTop2 - pS->pTop1;
}

/*
 * 入栈
 * pTop1 :
 *        if (满)
 *            ........
 *        else
 *            pS->data[++pS->pTop1] = val;
 *
 * pTop2:
 *        if (满)
 *            ........
 *        else
 *            pS->data[--pS->pTop2] = val;
 *
 */
int push(Stack *pS, int val, int flag)
{
    if (flag == 1)
    {
        if (fullStack(pS))
        {
            printf("pTop1 in stack is full!\n");  // 如需扩增内存请用realloc
            return -1;
        }
        else
        {
            pS->data[++pS->pTop1] = val;
            return 1;
        }
    }
    else       // flag == 2
    {
        if (fullStack(pS))
        {
            printf("pTop2 in stack is full!\n");  // 如需扩增内存请用realloc
            return -1;
        }
        else
        {
            pS->data[--pS->pTop2] = val;
            return 1;
        }
    }
}

/*
 * 判断栈空 pTop1：  pS->pTop1 = -1  pS->pTop2 = MAXSIZE
 */
int emptyStack(Stack *pS, int flag)
{
    if (flag == 1)
    {
        return -1 == pS->pTop1;
    }
    else
    {
        return MAXSIZE == pS->pTop2;
    }
}

/*
 * 出栈
 * pTop1 :
 *        if (空)
 *            ........
 *        else
 *            *pVal = pS->data[pS->pTop1--];
 *
 * pTop2:
 *        if (空)
 *            ........
 *        else
 *            *pVal = pS->data[pS->pTop2++];
 *
 */
int pop(Stack *pS, int *pVal, int flag)
{
    if (flag == 1)
    {
        if (emptyStack(pS,flag))
        {
            printf("pTop1 in Stack is empty!\n");
            return -1;
        }
        else
        {
            *pVal = pS->data[pS->pTop1--];
            return 1;
        }
    }
    else
    {
        if (emptyStack(pS,flag))
        {
            printf("pTop2 in Stack is empty!\n");
            return -1;
        }
        else
        {
            *pVal = pS->data[pS->pTop2++];
            return 1;
        }
    }
}

void traverse(Stack *pS, int flag)
{
    if (flag == 1)
    {
        if (emptyStack(pS,flag))
        {
            printf("pTop1 in Stack is empty, traverse is failed!\n");
            return;
        }
        printf("pTop1 is stack is : ");
        int i = pS->pTop1;
        while (i != -1)
        {
            printf(" %d ", pS->data[i--]);
        }
        printf("\n");
    }
    else
    {
        if (emptyStack(pS,flag))
        {
            printf("pTop2 in Stack is empty, traverse is failed!\n");
            return;
        }
        printf("pTop2 is stack is : ");
        int i = pS->pTop2;
        while (i != MAXSIZE)
        {
            printf(" %d ", pS->data[i++]);
        }
        printf("\n");
    }
}


//  栈的元素个数
int lengthStack(Stack *pS, int flag)
{
    // 对pTop1  堆栈1操作
    if (flag == 1)
    {
        return pS->pTop1 + 1;
    }
    else    // 对pTop2 堆栈2操作
    {
        return MAXSIZE - pS->pTop2;
    }
}
=======
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5                                 // 最大容量  如果不够可以用realloc
/**
 * 一个数组  实现两个堆栈
 * 解决：这两个栈分别从数组的两头开始向中间生长；当两个栈的栈顶指针相遇时，表示两个栈都满了
 */

typedef struct
{
    int data[MAXSIZE];                              // 定义数组 如果想要自定增长的话 可以写成 int *data; int maxSize; 配上realloc来自动增长
    int pTop1;                                      // 堆栈1 的栈顶指针
    int pTop2;                                      // 堆栈2 的栈顶指针
}Stack;

Stack * createStack();                              // 创建栈
int fullStack(Stack *pS);                           // 判断满   这里不需要 flag
int emptyStack(Stack *pS, int flag);                // 判断堆栈1 堆栈2 是否为空
int push(Stack *pS, int val, int flag);             // 入栈
int pop(Stack *pS, int *pVal, int flag);            // 出栈
void traverse(Stack *pS, int flag);                 // 遍历
int lengthStack(Stack *pS, int flag);               // 求 堆栈1或2的元素个数

// flag == 1 表示对 堆栈1 操作  pTop1
// flag != 1 表示对 堆栈2 操作  pTop2
int main(void)
{
    int val;
    // 用malloc 的方式 （堆） 来创建栈
    Stack * pS = createStack();
    // 对堆栈1进行操作
    printf("pTop1 length : %d\n",lengthStack(pS,1));
    printf("pTop2 length : %d\n",lengthStack(pS,2));

    push(pS,1,1);
    push(pS,2,1);
    if (pop(pS,&val,1))
    {
        printf("pTop1 pop is : %d\n", val);
    }
    push(pS,3,1);

    traverse(pS,1);
    traverse(pS,2);
    printf("pTop1 length : %d\n",lengthStack(pS,1));
    printf("pTop2 length : %d\n",lengthStack(pS,2));

    // 对堆栈2进行操作
    push(pS,10,2);
    if (pop(pS,&val,2))
    {
        printf("pTop2 pop is : %d\n", val);
    }
    push(pS,11,2);
    push(pS,99,2);
    printf("pTop1 length : %d\n",lengthStack(pS,1));
    printf("pTop2 length : %d\n",lengthStack(pS,2));
    traverse(pS,1);
    traverse(pS,2);

}

// 初始化 pTop1 = -1   pTop2 = MAXSIZE
Stack * createStack()
{
    Stack *pS = (Stack *)malloc(sizeof(Stack));
    if (NULL == pS)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pS->pTop1 = -1;
    pS->pTop2 = MAXSIZE;
}

// 判断满 当两个栈的栈顶指针相遇时，表示两个栈都满了 pS->Top1 + 1 = pS->pTop2
int fullStack(Stack *pS)
{
    return 1 == pS->pTop2 - pS->pTop1;
}

/*
 * 入栈
 * pTop1 :
 *        if (满)
 *            ........
 *        else
 *            pS->data[++pS->pTop1] = val;
 *
 * pTop2:
 *        if (满)
 *            ........
 *        else
 *            pS->data[--pS->pTop2] = val;
 *
 */
int push(Stack *pS, int val, int flag)
{
    if (flag == 1)
    {
        if (fullStack(pS))
        {
            printf("pTop1 in stack is full!\n");  // 如需扩增内存请用realloc
            return -1;
        }
        else
        {
            pS->data[++pS->pTop1] = val;
            return 1;
        }
    }
    else       // flag == 2
    {
        if (fullStack(pS))
        {
            printf("pTop2 in stack is full!\n");  // 如需扩增内存请用realloc
            return -1;
        }
        else
        {
            pS->data[--pS->pTop2] = val;
            return 1;
        }
    }
}

/*
 * 判断栈空 pTop1：  pS->pTop1 = -1  pS->pTop2 = MAXSIZE
 */
int emptyStack(Stack *pS, int flag)
{
    if (flag == 1)
    {
        return -1 == pS->pTop1;
    }
    else
    {
        return MAXSIZE == pS->pTop2;
    }
}

/*
 * 出栈
 * pTop1 :
 *        if (空)
 *            ........
 *        else
 *            *pVal = pS->data[pS->pTop1--];
 *
 * pTop2:
 *        if (空)
 *            ........
 *        else
 *            *pVal = pS->data[pS->pTop2++];
 *
 */
int pop(Stack *pS, int *pVal, int flag)
{
    if (flag == 1)
    {
        if (emptyStack(pS,flag))
        {
            printf("pTop1 in Stack is empty!\n");
            return -1;
        }
        else
        {
            *pVal = pS->data[pS->pTop1--];
            return 1;
        }
    }
    else
    {
        if (emptyStack(pS,flag))
        {
            printf("pTop2 in Stack is empty!\n");
            return -1;
        }
        else
        {
            *pVal = pS->data[pS->pTop2++];
            return 1;
        }
    }
}

void traverse(Stack *pS, int flag)
{
    if (flag == 1)
    {
        if (emptyStack(pS,flag))
        {
            printf("pTop1 in Stack is empty, traverse is failed!\n");
            return;
        }
        printf("pTop1 is stack is : ");
        int i = pS->pTop1;
        while (i != -1)
        {
            printf(" %d ", pS->data[i--]);
        }
        printf("\n");
    }
    else
    {
        if (emptyStack(pS,flag))
        {
            printf("pTop2 in Stack is empty, traverse is failed!\n");
            return;
        }
        printf("pTop2 is stack is : ");
        int i = pS->pTop2;
        while (i != MAXSIZE)
        {
            printf(" %d ", pS->data[i++]);
        }
        printf("\n");
    }
}


//  栈的元素个数
int lengthStack(Stack *pS, int flag)
{
    // 对pTop1  堆栈1操作
    if (flag == 1)
    {
        return pS->pTop1 + 1;
    }
    else    // 对pTop2 堆栈2操作
    {
        return MAXSIZE - pS->pTop2;
    }
}
>>>>>>> aaf7fc142a762ebeaad37deb1dc93dd632a040ea
