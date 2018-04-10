<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5                                 // �������  �������������realloc
/**
 * һ������  ʵ��������ջ
 * �����������ջ�ֱ���������ͷ��ʼ���м�������������ջ��ջ��ָ������ʱ����ʾ����ջ������
 */

typedef struct
{
    int data[MAXSIZE];                              // �������� �����Ҫ�Զ������Ļ� ����д�� int *data; int maxSize; ����realloc���Զ�����
    int pTop1;                                      // ��ջ1 ��ջ��ָ��
    int pTop2;                                      // ��ջ2 ��ջ��ָ��
}Stack;

Stack * createStack();                              // ����ջ
int fullStack(Stack *pS);                           // �ж���   ���ﲻ��Ҫ flag
int emptyStack(Stack *pS, int flag);                // �ж϶�ջ1 ��ջ2 �Ƿ�Ϊ��
int push(Stack *pS, int val, int flag);             // ��ջ
int pop(Stack *pS, int *pVal, int flag);            // ��ջ
void traverse(Stack *pS, int flag);                 // ����
int lengthStack(Stack *pS, int flag);               // �� ��ջ1��2��Ԫ�ظ���

// flag == 1 ��ʾ�� ��ջ1 ����  pTop1
// flag != 1 ��ʾ�� ��ջ2 ����  pTop2
int main(void)
{
    int val;
    // ��malloc �ķ�ʽ ���ѣ� ������ջ
    Stack * pS = createStack();
    // �Զ�ջ1���в���
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

    // �Զ�ջ2���в���
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

// ��ʼ�� pTop1 = -1   pTop2 = MAXSIZE
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

// �ж��� ������ջ��ջ��ָ������ʱ����ʾ����ջ������ pS->Top1 + 1 = pS->pTop2
int fullStack(Stack *pS)
{
    return 1 == pS->pTop2 - pS->pTop1;
}

/*
 * ��ջ
 * pTop1 :
 *        if (��)
 *            ........
 *        else
 *            pS->data[++pS->pTop1] = val;
 *
 * pTop2:
 *        if (��)
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
            printf("pTop1 in stack is full!\n");  // ���������ڴ�����realloc
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
            printf("pTop2 in stack is full!\n");  // ���������ڴ�����realloc
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
 * �ж�ջ�� pTop1��  pS->pTop1 = -1  pS->pTop2 = MAXSIZE
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
 * ��ջ
 * pTop1 :
 *        if (��)
 *            ........
 *        else
 *            *pVal = pS->data[pS->pTop1--];
 *
 * pTop2:
 *        if (��)
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


//  ջ��Ԫ�ظ���
int lengthStack(Stack *pS, int flag)
{
    // ��pTop1  ��ջ1����
    if (flag == 1)
    {
        return pS->pTop1 + 1;
    }
    else    // ��pTop2 ��ջ2����
    {
        return MAXSIZE - pS->pTop2;
    }
}
=======
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5                                 // �������  �������������realloc
/**
 * һ������  ʵ��������ջ
 * �����������ջ�ֱ���������ͷ��ʼ���м�������������ջ��ջ��ָ������ʱ����ʾ����ջ������
 */

typedef struct
{
    int data[MAXSIZE];                              // �������� �����Ҫ�Զ������Ļ� ����д�� int *data; int maxSize; ����realloc���Զ�����
    int pTop1;                                      // ��ջ1 ��ջ��ָ��
    int pTop2;                                      // ��ջ2 ��ջ��ָ��
}Stack;

Stack * createStack();                              // ����ջ
int fullStack(Stack *pS);                           // �ж���   ���ﲻ��Ҫ flag
int emptyStack(Stack *pS, int flag);                // �ж϶�ջ1 ��ջ2 �Ƿ�Ϊ��
int push(Stack *pS, int val, int flag);             // ��ջ
int pop(Stack *pS, int *pVal, int flag);            // ��ջ
void traverse(Stack *pS, int flag);                 // ����
int lengthStack(Stack *pS, int flag);               // �� ��ջ1��2��Ԫ�ظ���

// flag == 1 ��ʾ�� ��ջ1 ����  pTop1
// flag != 1 ��ʾ�� ��ջ2 ����  pTop2
int main(void)
{
    int val;
    // ��malloc �ķ�ʽ ���ѣ� ������ջ
    Stack * pS = createStack();
    // �Զ�ջ1���в���
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

    // �Զ�ջ2���в���
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

// ��ʼ�� pTop1 = -1   pTop2 = MAXSIZE
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

// �ж��� ������ջ��ջ��ָ������ʱ����ʾ����ջ������ pS->Top1 + 1 = pS->pTop2
int fullStack(Stack *pS)
{
    return 1 == pS->pTop2 - pS->pTop1;
}

/*
 * ��ջ
 * pTop1 :
 *        if (��)
 *            ........
 *        else
 *            pS->data[++pS->pTop1] = val;
 *
 * pTop2:
 *        if (��)
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
            printf("pTop1 in stack is full!\n");  // ���������ڴ�����realloc
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
            printf("pTop2 in stack is full!\n");  // ���������ڴ�����realloc
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
 * �ж�ջ�� pTop1��  pS->pTop1 = -1  pS->pTop2 = MAXSIZE
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
 * ��ջ
 * pTop1 :
 *        if (��)
 *            ........
 *        else
 *            *pVal = pS->data[pS->pTop1--];
 *
 * pTop2:
 *        if (��)
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


//  ջ��Ԫ�ظ���
int lengthStack(Stack *pS, int flag)
{
    // ��pTop1  ��ջ1����
    if (flag == 1)
    {
        return pS->pTop1 + 1;
    }
    else    // ��pTop2 ��ջ2����
    {
        return MAXSIZE - pS->pTop2;
    }
}
>>>>>>> aaf7fc142a762ebeaad37deb1dc93dd632a040ea
