#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

/**
 *  �õݹ��������������� �ݹ������������
 */

typedef int elemType;                        // ��int����ȡ������ ������������������

typedef struct Node{
    elemType data;                           // ����ڵ��������
    struct Node * pLChild;                   // ����ڵ����ָ��
    struct Node * pRChild;                   // ����ڵ����ָ��
}BiTNode;

typedef struct {
    BiTNode * Data[MAXSIZE];                 // ���洢��������ڵ�ĵ�ַ  -- ѭ��˳�����
    int front;                               // ����ָ�� ָ����ǵ�һ����ЧԪ�ص�ǰ��һ��λ��
    int rear;                                // ��βָ�� ָ��������һ����ЧԪ�ص�λ��
}Queue;

BiTNode * createTree();                      // ���õݹ�ķ�ʽ����������
void preOrderTraverse(BiTNode * pT);         // �������
void inOrderTraverse(BiTNode * pT);          // �������
void postOrderTraverse(BiTNode * pT);        // �������
void levelOrderTraverse(BiTNode * pT);       // ��α���  ������ ������ʵ��

Queue * createQueue();                       // ��������
BiTNode *out_Queue(Queue *pQ);
int is_empty(Queue * pQ);
void in_Queue(Queue * pQ, BiTNode * pT);
int is_full(Queue * pQ);

int main(void)
{

    BiTNode * pT = createTree();
    printf("�������: ");
    preOrderTraverse(pT);

    printf("\n�������: ");
    inOrderTraverse(pT);

    printf("\n�������: ");
    postOrderTraverse(pT);

    printf("\n��α���: ");
    levelOrderTraverse(pT);

}

// �������������˳�� �ݹ�������������
BiTNode * createTree()
{
    BiTNode * pT;
    elemType val;
    scanf("%d", &val);

    // �������0 ˵���ýڵ�Ϊ��
    if (val == 0)
    {
        pT = NULL;
    }
    else
    {
        pT = (BiTNode *) malloc(sizeof(BiTNode));
        if (!pT)
        {
            printf("malloc is failed!\n");
            exit(-1);
        }
        // �� ���� DLR  �����ҵ�˳��ݹ�����
        pT->data = val;                              // ���ɸ��ڵ�
        printf("������%d�ڵ�����ӣ�\n", pT->data);
        pT->pLChild = createTree();                // ���ɸýڵ������
        printf("������%d�ڵ���Һ��ӣ�\n", pT->data);
        pT->pRChild = createTree();                // ���ɸýڵ���Һ���

    }
    return pT;
}


void preOrderTraverse(BiTNode * pT)
{
    // ���pT ��= NULL
    if (pT)
    {
        printf(" %d ", pT->data);           // �ȱ������ڵ�
        preOrderTraverse(pT->pLChild);      // �ٱ���������
        preOrderTraverse(pT->pRChild);      // �ٱ���������
    }
}

void inOrderTraverse(BiTNode * pT)
{
    // ���pT ��= NULL
    if (pT)
    {
        inOrderTraverse(pT->pLChild);       // ����������
        printf(" %d ", pT->data);           // �������ڵ�
        inOrderTraverse(pT->pRChild);       // ����������
    }
}

void postOrderTraverse(BiTNode * pT)
{

    // ���pT ��= NULL
    if (pT)
    {
        postOrderTraverse(pT->pLChild);       // ����������
        postOrderTraverse(pT->pRChild);       // ����������
        printf(" %d ", pT->data);           // �������ڵ�
    }
}

void levelOrderTraverse(BiTNode * pT)
{
    // ����ǿ���  ֱ�ӷ���
    if (!pT)
    {
        return;
    }
    Queue *pQ = createQueue();                  // ��������
    in_Queue(pQ, pT);                           // ���ĸ��ڵ����
    // ֻҪ���в�Ϊ��
    while (!is_empty(pQ))
    {
        BiTNode * p = out_Queue(pQ);            // ���ڵ����
        printf(" %d ", p->data);                // ��ӡ���ڵ��ֵ
        if (p->pLChild)
        {
            in_Queue(pQ, p->pLChild);           // �����ڵ���������
        }
        if (p->pRChild)
        {
            in_Queue(pQ, p->pRChild);           // �����ڵ���Һ������
        }

    }

}
/******************�������и���α����й�********************/
Queue * createQueue()
{
    Queue * pQ = (Queue *) malloc (sizeof(Queue));
    if (!pQ)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pQ->front = pQ->rear = 0;
}

int is_full(Queue * pQ)
{
    return pQ->front == (pQ->rear + 1) % MAXSIZE;
}

// ���� ֻ��rear�й�
void in_Queue(Queue * pQ, BiTNode * pT)
{
    if (is_full(pQ))
    {
        printf("Queue is full!\n");
        return;
    }
    pQ->rear = (pQ->rear + 1) % MAXSIZE;
    pQ->Data[pQ->rear] = pT;
}

int is_empty(Queue * pQ)
{
    return pQ->front == pQ->rear;
}

// ����ֻ�� front�й�
BiTNode *out_Queue(Queue *pQ)
{
    if (is_empty(pQ))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        pQ->front = (pQ->front +1) % MAXSIZE;
        return pQ->Data[pQ->front];
    }
}


