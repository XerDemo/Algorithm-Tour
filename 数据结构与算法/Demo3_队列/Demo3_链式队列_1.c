#include <stdio.h>
#include <stdlib.h>
/*
	 ��ʽ���У�
	 	 
*/
typedef struct node {
    int data;
    struct node *pNext;
} queueNode;

typedef struct {
    queueNode *front;
    queueNode *rear;
    int count;
} Queue;


Queue *createQueue();                                          // ��������
void inQueue(Queue *pQ, int val);                              // ����
int outQueue(Queue *pQ);                                       // ����
int emptyQueue(Queue *pQ);                                     // �ж϶����Ƿ�Ϊ��
void traverseQueue(Queue *pQ);                                 // ��������
void clearQueue(Queue *pQ);                                    // ��ն���
void destroyQueue(Queue *pQ);                                  // ���ٶ���

int main(void)
{
    Queue *pQ = createQueue();
    printf("pQ->front = %p   pQ->rear = %p\n", pQ->front,pQ->rear);
    inQueue(pQ,1);
    inQueue(pQ,2);
    inQueue(pQ,3);
    printf("����Ԫ�أ�%d\n", outQueue(pQ));
    inQueue(pQ,4);
    printf("���г��ȣ�%d\n", pQ->count);
    traverseQueue(pQ);

    printf("��ն��У�\n");
    clearQueue(pQ);
    printf("���г��ȣ�%d\n", pQ->count);
    traverseQueue(pQ);

    inQueue(pQ,10);
    inQueue(pQ,11);
    printf("���г��ȣ�%d\n", pQ->count);
    traverseQueue(pQ);

    printf("���ٶ��У�\n");
    destroyQueue(pQ);
    printf("pQ->front = %p   pQ->rear = %p\n", pQ->front,pQ->rear);
    return 0;
}

// ��ʼ������
Queue *createQueue()
{
    Queue *pQ = (Queue *) malloc(sizeof(Queue));
    pQ->front = (queueNode *) malloc(sizeof(queueNode));
    // ʡ���ж� pQ  pQ->front �Ƿ�Ϊ��
    pQ->rear = pQ->front;
    pQ->rear->pNext = NULL;
    pQ->count = 0;
    return pQ;
}

void inQueue(Queue *pQ, int val)
{
    queueNode *pNew = (queueNode *) malloc(sizeof(queueNode));
    pNew->data = val;
    pNew->pNext = NULL;
    pQ->rear->pNext = pNew;
    pQ->rear = pNew;
    pQ->count++;
}

// �ж϶����Ƿ�Ϊ��
int emptyQueue(Queue *pQ)
{
    return NULL == pQ->front;
}

int outQueue(Queue *pQ)
{
    int val;
    if (emptyQueue(pQ))
    {
        printf("��ʽ����Ϊ�գ�\n");
        return -999999;
    }
    queueNode *pTemp = pQ->front->pNext;
    val = pTemp->data;
    pQ->front->pNext = pTemp->pNext;
    free(pTemp);
    pTemp = NULL;
    pQ->count--;
    return val;
}

void traverseQueue(Queue *pQ)
{
    queueNode *p = pQ->front->pNext;
    if (emptyQueue(pQ))
    {
        printf("�����п� !\n");
        return;
    }
    printf("��ʽ���У�");
    while (p)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

// ��ն���  ����������ʱ�ڵ�  ��ͷ�ڵ�֮��ĵ�һ����Ч�Ľڵ㿪ʼ �ͷſռ�
void clearQueue(Queue *pQ)
{
    queueNode *p = pQ->front->pNext;      // �׽ڵ�  ����һ����ЧԪ�صĽڵ㣩
    queueNode *q;
    while (p)
    {
        q = p->pNext;
        free(p);
        p = q;
    }
    /*  ���������һ��д��
    PNODE p = pQ->front->pNext;      // �׽ڵ�  ����һ����ЧԪ�صĽڵ㣩
    while (p)                        // ��Ϊ�� ��ִ��
    {
        PNODE temp = p;
        p = p->pNext;
        free(temp);
    }
    */

    // ��whileִ���� ͷ�ڵ�֮��Ķ���ɾ����  countΪ0     ͷ�ڵ��pNext = NULL   rearָ��ͷ�ڵ�
    pQ->count = 0;
    pQ->front->pNext = NULL;
    pQ->rear = pQ->front;
}

// ���ٶ���
void destroyQueue(Queue *pQ)
{
    queueNode *p = pQ->front->pNext;
    queueNode *q;
    while (p)
    {
        q = p->pNext;
        free(p);
        p = q;
    }
    pQ->count = 0;
    pQ->front = pQ->rear = NULL;
}
