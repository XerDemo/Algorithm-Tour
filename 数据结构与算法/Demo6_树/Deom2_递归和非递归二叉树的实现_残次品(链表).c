#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 100                                        // ���ڵ����

typedef int elemType;                                       // ������Ԫ������

// �������ڵ�
typedef struct Node{
    elemType data;                                          // �ڵ��������
    struct Node * pLChild;                                  // �ڵ����ָ����
    struct Node * pRChild;                                  // �ڵ����ָ����
}BTNode;

// ����ջ
typedef struct stack{
    BTNode* data[MAX_NODE];                                  // ��ŵ��ǽڵ� ������BTNode ����
    int top;                                                // ջ��ָ��
}Stack;

// �������
typedef struct {
    BTNode * Data[MAX_NODE];                 // ���洢��������ڵ�ĵ�ַ  -- ѭ��˳�����
    int front;                               // ����ָ�� ָ����ǵ�һ����ЧԪ�ص�ǰ��һ��λ��
    int rear;                                // ��βָ�� ָ��������һ����ЧԪ�ص�λ��
}Queue;



BTNode * createTree();                                      // ����������
Stack * createStack();                                      // ����˳��ջ
int fullStack(Stack * pS);                                  // �ж϶�ջ�Ƿ���
int emptyStack(Stack *pS);                                  // �ж϶�ջ�Ƿ��
void push(Stack *pS, BTNode * pT);                          // ��ջ
BTNode * pop(Stack *pS);                                    // ��ջ

Queue * createQueue();                                      // ��������
BTNode *out_Queue(Queue *pQ);
int is_empty(Queue * pQ);
void in_Queue(Queue * pQ, BTNode * pT);
int is_full(Queue * pQ);

void preOrderTraverse_1(BTNode * pT);                       // �ݹ��������    ���ö�ջ
void inOrderTraverse_1(BTNode * pT);                        // �ݹ��������    ���ö�ջ
void postOrderTraverse_1(BTNode * pT);                      // �ݹ�������    ���ö�ջ
int leafNum_1(BTNode * pT);                                 // �ݹ� ��Ҷ�ڵ����

void preOrderTraverse_2(BTNode * pT);                       // �ǵݹ� ������� ʹ�ö�ջ
void inOrderTraverse_2(BTNode * pT);                        // �ǵݹ� ������� ʹ�ö�ջ
//void postOrderTraverse_2(BTNode * pT);                    // �ǵݹ� ������� ʹ�ö�ջ     δʵ��
void levelOrderTraverse(BTNode * pT);                       // �ǵݹ��α���
int leafNum_2(BTNode * pT);                                 // �ǵݹ� ��Ҷ�ӽڵ����   ��������������޸�


int main(void)
{
    BTNode * pT = createTree();
    printf("�ݹ��������:");
    preOrderTraverse_1(pT);

    printf("\n�ݹ��������:");
    inOrderTraverse_1(pT);

    printf("\n�ݹ�������:");
    postOrderTraverse_1(pT);

    printf("\n�ݹ��α���:(����)");

    printf("\n�ݹ�Ҷ�ڵ�ĸ�����%d\n", leafNum_1(pT));

    printf("\n�ǵݹ��������:");
    preOrderTraverse_2(pT);

    printf("\n�ǵݹ��������:");
    inOrderTraverse_2(pT);

    printf("\n�ǵݹ�������:�����ޣ�");

    printf("\n�ǵݹ��α���:");
    inOrderTraverse_2(pT);

    printf("\n�ǵݹ�Ҷ�ڵ�ĸ�����%d\n", leafNum_2(pT));

    return 0;
}

// ����α�����������  �����źͽڵ��ֵ
BTNode * createTree()
{
    int idx;                                                // ����ڵ�ı��  ��1��ʼ (0����)
    elemType val;                                           // �ڵ��������
    BTNode * arr[MAX_NODE];                                 // ������������  ÿ���ڵ�ĵ�ַ
    BTNode * pT;                                            // �������ĸ��ڵ�

    while (1)
    {
        scanf("%d %d", &idx, &val);
        if (idx == 0)
        {
            break;
        }
        else
        {
            // �����µĽڵ�
            BTNode *pNew = (BTNode *) malloc(sizeof(BTNode));
            pNew->data = val;
            pNew->pRChild = pNew->pLChild = NULL;
            arr[idx] = pNew;                                // ���ñ��Ϊidx�Ľڵ�ĵ�ַ���浽   arr[idx]

            // �����idx==1 ���������ĸ��ڵ�
            if (idx == 1)
            {
                pT= pNew;
            }
            else
            {
                int father_idx = idx / 2;                  // ���Ϊidx�ڵ㸸�׽ڵ�ı��

                if (idx % 2 == 0)                          // ���������
                {
                    arr[father_idx]->pLChild = pNew;
                }
                else                                       // ������Һ���
                {
                    arr[father_idx]->pRChild = pNew;
                }
            }
        }
    }
    return pT;
}


// �ݹ��������
void preOrderTraverse_1(BTNode * pT)
{
    // ���ǿ�
    if (pT)
    {
        printf("%d ", pT->data);                         // �ȱ������ڵ�
        preOrderTraverse_1(pT->pLChild);                 // �ٱ���������
        preOrderTraverse_1(pT->pRChild);                 // ������������
    }
}

// �ݹ��������
void inOrderTraverse_1(BTNode * pT)
{
    if (pT)
    {
        inOrderTraverse_1(pT->pLChild);
        printf("%d ", pT->data);
        inOrderTraverse_1(pT->pRChild);
    }
}

// �ݹ�������
void postOrderTraverse_1(BTNode * pT)
{
    if (pT)
    {
        postOrderTraverse_1(pT->pLChild);
        postOrderTraverse_1(pT->pRChild);
        printf("%d ", pT->data);
    }
}

// �ǵݹ�  �������
void preOrderTraverse_2(BTNode * pT)
{
    BTNode *p = pT;                 // ����һ���ڵ���� pT ,�����ڱ�����ʱ�� ����ı� pT��ֵ
    Stack * pS = createStack();     // ����һ����ջ
    while (p || !emptyStack(pS))    // ������ ���� ��ջ���վͿ���һֱִ�� while
    {
        while (p)                   // ���ڵ㲻��
        {
            push(pS, p);            // ֻҪ�����վ�һֱ ���������� ������;�Ľڵ� ��ջ
            printf("%d ", p->data); // ��ӡ���ڵ��ֵ
            p = p->pLChild;
        }
        if (!emptyStack(pS))        // �˽ڵ�Ϊ�� ��ջ ����������
        {
            p = pop(pS);
            p = p->pRChild;
        }
    }
}
// �ǵݹ�  �������
void inOrderTraverse_2(BTNode * pT)
{
    BTNode * p = pT;
    Stack * pS = createStack();                         // ������ջ
    // ֻҪ������  ���� ��ջ���� ��һֱִ��while
    while (p || !emptyStack(pS))
    {
        // ֻҪ�����վ�һֱ ���������� ������;�Ľڵ� ��ջ
        while (p)
        {
            push(pS, p);
            p = p->pLChild;
        }
        // ��� ��ջ����  ��ʱ��������  �ڵ��ջ ��ӡ�ڵ� ת��������
        if (!emptyStack(pS))
        {
            p= pop(pS);             // ע��������T ������Ūһ����ʱ�ڵ�
            printf("%d ", p->data);
            p = p->pRChild;
        }
    }
}

// �ǵݹ�������
void levelOrderTraverse(BTNode * pT)
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
        BTNode * p = out_Queue(pQ);            // ���ڵ����
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

// �ݹ� ��Ҷ�Ӹ���   ���յݹ����������
int leafNum_1(BTNode * pT)
{
    static int num = 0;
    // ���������
    if (pT)
    {
        if (pT->pLChild == NULL && pT->pRChild == NULL)
        {
            num++;
        }
        leafNum_1(pT->pLChild);
        leafNum_1(pT->pRChild);
    }
    return num;
}

//// ��Ҷ�ӽڵ�������ǵݹ飩      д������
//int leafNum_2(BTNode * pT)
//{
//    BTNode * p = pT;
//    int num = 0;
//    Stack *pS = createStack();
//    while (p || !emptyStack(pS))
//    {
//        while (p)
//        {
//            push(pS, p);
//            p = p->pLChild;
//        }
//        if (!emptyStack(pS))
//        {
//            p = pop(pS);
//            p = p->pRChild;
//            if (p == NULL)      // ���ǵݹ�ǰ��ͬ����������˸��ж�����   ��һ�����ִ���൱�� �����Һ��Ӷ�ΪNULL
//            {
//                num++;
//            }
//        }
//    }
//}

/******************����ջ**************************/
Stack * createStack()
{
    Stack *pS = (Stack *) malloc(sizeof(Stack));
    // ʡ���ж��Ƿ�Ϊ ��
    pS->top = -1;
}

int fullStack(Stack * pS)
{
    return MAX_NODE - 1 == pS->top;
}

int emptyStack(Stack * pS)
{
    return -1 == pS->top;
}

void push(Stack * pS, BTNode * pT)
{
    if (fullStack(pS))
    {
        printf("Stack is full! push is failed\n");
        return;
    }
    pS->data[++pS->top] = pT;
}

BTNode * pop(Stack *pS)
{
    if (emptyStack(pS))
    {
        printf("Stack is empty! pop is failed!\n");
    }
    else
    {
        return pS->data[pS->top--];
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
    return pQ->front == (pQ->rear + 1) % MAX_NODE;
}

// ���� ֻ��rear�й�
void in_Queue(Queue * pQ, BTNode * pT)
{
    if (is_full(pQ))
    {
        printf("Queue is full!\n");
        return;
    }
    pQ->rear = (pQ->rear + 1) % MAX_NODE;
    pQ->Data[pQ->rear] = pT;
}

int is_empty(Queue * pQ)
{
    return pQ->front == pQ->rear;
}

// ����ֻ�� front�й�
BTNode *out_Queue(Queue *pQ)
{
    if (is_empty(pQ))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        pQ->front = (pQ->front +1) % MAX_NODE;
        return pQ->Data[pQ->front];
    }
}



