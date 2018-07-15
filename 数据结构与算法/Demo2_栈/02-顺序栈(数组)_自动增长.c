#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10                                       // ˳��ջ���������
#define INCREAMENT 5                                     // ��������  ÿ������5
/**
 * ˳��ջ(����)
 * �Ƚ����   ����ȳ�
 *
 */

typedef struct stack
{
    int *data;                                         // ����ռ��ַ
    int maxsize;                                        // �����С
    int top;                                            // ջ��ָ�� ָ���������һ��Ԫ�ص��±�  ��ʼʱΪ�գ�-1  ��һ��Ԫ�أ�0 �Դ�����
} seqStack;

seqStack *createSeqStack();                             // ��ʼ��
int emptySeqStack(seqStack *pS);                        // �ж�˳��ջ �Ƿ�Ϊ��
int fullSeqStack(seqStack *pS);                         // �ж�˳��ջ �Ƿ���
int push(seqStack *pS, int val);                        // ��ջ
int pop(seqStack *pS, int *pVal);                       // ��ջ
int lengthSeqStack(seqStack *pS);                       // ��ջ��Ԫ�صĸ���
void traverse(seqStack *pS);                            // ����


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
    // ʡ�� �ж� pS  pS->data Ϊ��
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
        // ��ʱ�������׵�ַ pTemp  ��֮ǰ�Ŀռ�� ��СΪ (pS->maxsize + INCREAMENT) * sizeof(int)
        int *pTemp = (int *) realloc(pS->data, (pS->maxsize + INCREAMENT) * sizeof(int));
        pS->data = pTemp;
        pS->maxsize += INCREAMENT;
    }
    // ����ǧ���ܼ� else Ҫ��Ȼ��ջ����ʱ�� ֻ��ִ��if ,else�Ĳ���ִ��
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
    int i = pS->top;                              // ����һ������������top ��������֮��pS->top�Ĳ���  �����i
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
