#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

/**
 *  �õ����������˳�� �ݹ��������������� �ݹ������������
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

void levelOrderTraverse_1(BiTNode * pT);     // ��α���  ������ģ�� ˳�����   

int leafNum(BiTNode * pT);                   // ��Ҷ�ڵ����   �ݹ�
int nodeNum(BiTNode * pT);                   // ͳ�ƽڵ�����
int treeDepth(BiTNode * pT);                 // ������������
BiTNode * searchTree(BiTNode * pT, elemType val);   // ��������Ԫ��val �������ַ


Queue * createQueue();                       // ��������
BiTNode *out_Queue(Queue *pQ);               // ����
int is_empty(Queue * pQ);                    // �����Ƿ�Ϊ��
void in_Queue(Queue * pQ, BiTNode * pT);     // ���
int is_full(Queue * pQ);                     // �����Ƿ���

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
    
    printf("\n����ģ���Σ�");
	levelOrderTraverse_1(pT);
    printf("\n");

    printf("Ҷ�ڵ����:%d\n", leafNum(pT));

    printf("���нڵ�����%d\n", nodeNum(pT));

    printf("���:%d\n", treeDepth(pT));

    printf("����Ԫ��Ϊ13�ĵ�ַ��%p\n", searchTree(pT, 13));

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
            exit(0);
        }
        // �� ���� DLR  �����ҵ�˳��ݹ�����
        pT->data = val;                            // ���ɸ��ڵ�
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
        printf(" %d ", pT->data);             // �������ڵ�
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

// ����ģ��˳����� ʵ�� ��α���
void levelOrderTraverse_1(BiTNode * pT)
{
	int front, rear;                // ��ͷ  ��β
    BiTNode *arr[100];              // ����ģ�����
    BiTNode *p = pT;
    // ֻҪ������
    if (p)
    {
        front = 0;
        arr[front] = p;            // ���ڵ����
        rear = 1;
    }
    // ֻҪ���в���
    while (front != rear)
    {
        p = arr[front];

        front++;                   // ��������
        printf("%d  ", p->data);    // ��ӡ���ڵ�

        if (p->pLChild)            // ������Ӳ��� ��� rear����
        {
            arr[rear++] = p->pLChild;
        }
        if (p->pRChild)            // ������Ӳ��� ��� rear����
        {
            arr[rear++] = p->pRChild;
        }
    }
} 

// �����ڵݹ���������Ļ����� ����һ���ж���������
int leafNum(BiTNode * pT)
{
    static int num = 0;
    if (pT)
    {
        if (pT->pLChild == NULL && pT->pRChild == NULL)     // ��� ��Ҷ�ӽڵ�
        {
            num++;                              // ͳ��Ҷ�ڵ����
            printf("Ҷ�ӽڵ㣺%d\n", pT->data);
        }
        leafNum(pT->pLChild);                   // ͳ��pT��������Ҷ�ڵ����
        leafNum(pT->pRChild);                   // ͳ��pT��������Ҷ�ڵ����
    }
    return num;
}

// �ڵ�����
int nodeNum(BiTNode * pT)
{
    static int num = 0;                         // ��¼�ڵ�����
    if (pT)
    {
        num++;
        nodeNum(pT->pLChild);
        nodeNum(pT->pRChild);
    }
    return num;
}

// ������������
int treeDepth(BiTNode * pT)
{
    int leftDepth, rightDepth;                  // leftDept��pT�����������   rightDepth��pT�����������
    if (NULL == pT)                             // ��������򷵻� 0
    {
        return 0;
    }
    leftDepth = treeDepth(pT->pLChild);
    rightDepth = treeDepth(pT->pRChild);
    if (leftDepth > rightDepth){
        return leftDepth + 1;                   // ���������������  +  ���ڵ㣺1
    } else{
        return rightDepth + 1;                  // ������������� + ���ڵ�
    }
}

// �ڶ������� ����ĳ��Ԫ�� �������ַ

BiTNode * searchTree(BiTNode * pT, int val)
{
    BiTNode * p = pT;
    if (p!=NULL)                                     // �������Ϊ��
    {
        if (val= p->data)                       // ������ڵ� ����Ҫ���ҵĽڵ� ֱ�ӷ��ظ�  ���򣬷ֱ���������������
        {
            return p;
        }
        p = searchTree(p->pLChild,val);         // ����p->pLChild�ĸ��ڵ�Ķ������еݹ��������Ԫ��val
        if (NULL != p)
        {
            return p;                           // ����ҵ�  ����p
        } else{
           return  p = searchTree(p->pRChild, val);
        }
    } else{
        return NULL;                            // ����ʧ�� ���ؿ�
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


