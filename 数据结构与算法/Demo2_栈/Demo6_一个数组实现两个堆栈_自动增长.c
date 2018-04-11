#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5                                          // �����ʼ�������
#define INCREATEMENT 5                                     // ��������  ��realloc ʵ�ֶ�����ռ�������� ÿ������5��

/**
 * һ������ʵ�ֶ�ջ �Զ�����
 * flag == 1 �� pTop1���ڶ�ջ���в���  flag == 2 �� pTop2���ڶ�ջ���в���
 */
typedef struct
{
    char * data;                                            // �ַ�����
    int maxsize;                                            // �������
    int pTop1;                                              // pTop1 ջ��ָ��
    int pTop2;                                              // pTop2 ջ��ָ��
}seqStack;

seqStack * createStack();                                   // ��ջ���г�ʼ��
void push(seqStack *pS, int val, int flag);                 // ��ջ
int pop(seqStack *pS,  int flag);                           // ��ջ
void traverse(seqStack *pS, int flag);                      // ����
int lengthStack(seqStack * pS, int flag);                   // ��ջ��Ԫ��

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
    printf("pTop1 ���ڶ�ջ���ȣ�%d\n",lengthStack(pS,1));
    printf("pTop2 ���ڶ�ջ���ȣ�%d\n",lengthStack(pS,2));

    return 0;
}

// ��ʼ��
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
// ��ջ
void push(seqStack *pS, int val, int flag)
{
    // ���ջ��
    if (1 == pS->pTop2 - pS->pTop1)
    {
        // realloc�������Ŀռ�
        char *pTemp = (char *) realloc(pS->data, sizeof(char) * (pS->maxsize + INCREATEMENT));
        if (!pTemp)
        {
            printf("malloc is failed\n");
            exit(-1);
        }
        // ������Ŀռ丳��pS->data
        pS->data = pTemp;
        // �������󳤶� ����
        pS->maxsize += INCREATEMENT;

        // ͬʱpTop2ջ�ڵ�Ԫ���Ƶ���������ռ��Ӧ��λ�ã� pTop1����Ҫ�ƶ� ��ͼ��֪����
        int i, k;      // i��δ�����ռ�ʱ��pTop2������   k��pTopջ��Ԫ�ظ���
        for (i = pS->pTop2, k = 0; k < lengthStack(pS, 2); ++i, ++k)
        {
            //i + INCREATEMENT�� ����INCREATEMENT�ռ���Ӧ��pS->pTop2������
            pS->data[i + INCREATEMENT] = pS->data[i];
        }
        // ����pTop2��λ��
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
            printf("pTop1 ����ջ �գ�\n");
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
            printf("pTop2 ����ջ �գ�\n");
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
            printf("pTop1 ����ջ ��\n");
            return ;
        }
        printf("pTop1 ջ : ");
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
            printf("pTop2 ����ջ �գ�\n");
            return ;
        }

        int i = pS->pTop2;
        printf("pTop2 ջ : ");
        while (pS->maxsize != i)
        {
            printf(" %d ", pS->data[i++]);
        }
        printf("\n");
    }
}
