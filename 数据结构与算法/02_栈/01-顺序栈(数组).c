#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10                                       // ˳��ջ���������  ���� realloc ����
/**
 * ˳��ջ(����)
 * �Ƚ����   ����ȳ�
 *
 */

typedef struct stack
{
    int data[MAXSIZE];                                   // ��������
    int top;                                             // ջ��ָ�� ָ���������һ��Ԫ�ص��±�  ��ʼʱΪ�գ�-1  ��һ��Ԫ�أ�0 �Դ�����
} seqStack;

void initSeqStack(seqStack *pS);                        // ��ʼ����ʽ1����ջ�з���
seqStack *createSeqStack();                             // ��ʼ����ʽ2���ڶ��з���  (�˴�ѡ���ڡ��ѡ��з���)
int emptySeqStack(seqStack *pS);                        // �ж�˳��ջ �Ƿ�Ϊ��
int fullSeqStack(seqStack *pS);                         // �ж�˳��ջ �Ƿ���
int push(seqStack *pS, int val);                        // ��ջ
int pop(seqStack *pS, int *pVal);                       // ��ջ
int lengthSeqStack(seqStack *pS);                       // ��ջ��Ԫ�صĸ���
void traverse(seqStack *pS);                            // ����


int main(void)
{
    // ��ʼ����ʽ1�� ʹ�� ���������ķ�ʽ �ڣ�ջ��"�ڿ�"
    seqStack S;
    initSeqStack(&S);

    // ��ʼ����ʽ2�� ʹ�� malloc  �ڣ��ѣ�  "�ڿ�"  malloc��Ҫͷ�ļ� stdlib.h
    // �ڴ�ѡ�õڶ��ַ�ʽ
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

//������ջ ��ʼ�� ��top����-1ʱ ��ʾջ��    top����MAXSIZE-1ʱ ��ʾջ�� 
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
//��ִ��push����ʱ�����ȿ�ջ�Ƿ��� ;��������top+1 ��������Ԫ�ط���data�����topλ�� 
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
