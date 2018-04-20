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




BTNode * createTree();                                      // ����������
Stack * createStack();                                      // ����˳��ջ
int fullStack(Stack * pS);                                  // �ж϶�ջ�Ƿ���
int emptyStack(Stack *pS);                                  // �ж϶�ջ�Ƿ��
void push(Stack *pS, BTNode * pT);                          // ��ջ
BTNode * pop(Stack *pS);                                    // ��ջ

void preOrderTraverse_1(BTNode * pT);                       // �ݹ��������    ���ö�ջ
void inOrderTraverse_1(BTNode * pT);                        // �ݹ��������    ���ö�ջ
void postOrderTraverse_1(BTNode * pT);                      // �ݹ�������    ���ö�ջ

void preOrderTraverse_2(BTNode * pT);                       // �ǵݹ� ������� ʹ�ö�ջ
void inOrderTraverse_2(BTNode * pT);                        // �ǵݹ� ������� ʹ�ö�ջ
//void postOrderTraverse_2(BTNode * pT);                      // �ǵݹ� ������� ʹ�ö�ջ



int main(void)
{
    BTNode * pT = createTree();
    printf("�ݹ��������:");
    preOrderTraverse_1(pT);

    printf("\n�ݹ��������:");
    inOrderTraverse_1(pT);

    printf("\n�ݹ�������:");
    postOrderTraverse_1(pT);

    printf("\n�ǵݹ��������:");
    preOrderTraverse_2(pT);

    printf("\n�ǵݹ��������:");
    inOrderTraverse_2(pT);

    return 0;
}

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


