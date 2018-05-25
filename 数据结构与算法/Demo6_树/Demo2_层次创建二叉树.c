#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100                                // �洢��������ַ������������ Ҳ�Ƕ��������������
/*
   ʹ�� ��α����ķ�ʽ ����������
     ����һ����n�����Ķ�������������������ϵ��¡������ҵ�˳��������
     �����������Ϊi�Ľ���У�
       (1)��i = 1�������Ϊi�Ľ���Ǹ��ڵ�
          ��i > 1�������Ϊi�Ľ��ĸ��ڵ�����Ϊ [ i/2 ] (ȡ��)
       (2)��2i �� n�������Ϊi�Ľ������ӽ������Ϊ 2i
          ��2i > n�� ��i���������
       (3)��2i + 1�� n�������Ϊi�Ľ����Һ��ӽ������Ϊ 2i+1
          ��2i +1 > n����i������Һ���
*/


typedef int elemType;                               // ��int����Ȣ������ �� elemType

// �����
typedef struct Node{
    elemType data;
    struct Node * pLChild;
    struct Node * pRChild;
}BTNode;

// ����ѭ������
typedef struct {
    BTNode * data[MAXSIZE];                         // ��������ĵ�ַ
    int front;                                      // ��ͷָ��  ָ�����Ԫ�ص�ǰ��һ��λ��
    int rear;                                       // ��βָ��  ָ�����Ԫ�ص����һ��λ��
}cycleQueue;


BTNode * createTree();                              // ��α��� ���� ������
void preOrderTraverse(BTNode * pT);                 // �ݹ��������������
void inOrderTraverse(BTNode * pT);                  // �ݹ��������������
void postOrderTraverse(BTNode * pT);                // �ݹ�������������
void leverOrderTraverse(BTNode * pT);               // ��α���  ����� ����
void leafNum(BTNode * pT);                          // �ݹ�ͳ��Ҷ�ڵ�ĸ��� ��ӡҶ�ڵ�
int nodeNum(BTNode * pT);                           // �ݹ�ͳ�� ���������ܽ����
int treeDepth(BTNode * pT);                         // �ݹ�ͳ�� �����������

// ѭ������
cycleQueue * createQueue();                         // ����ѭ������
void inQueue(cycleQueue * pQ, BTNode * val);        // ���
BTNode * outQueue(cycleQueue * pQ);                 // ����
int isFull(cycleQueue * pQ);                        // �ж�ѭ�������Ƿ���
int isEmpty(cycleQueue * pQ);                       // �ж϶����Ƿ��

int main(void)
{
    BTNode * pT = createTree();

    printf("�ݹ��������: ");
    preOrderTraverse(pT);

    printf("\n�ݹ��������: ");
    inOrderTraverse(pT);

    printf("\n�ݹ�������: ");
    postOrderTraverse(pT);

    printf("\n��α���: ");
    leverOrderTraverse(pT);

    printf("Ҷ�ӽ�㣺");
    leafNum(pT);

    printf("\n���������ܽ����:%d\n", nodeNum(pT));

    printf("����������ȣ�%d\n", treeDepth(pT));
    return 0;
}

/*
 * ��� ����������
 * ����˼�룺 ͨ������ ��� �� ֵ����ʽ��������� ������Ϊ0 ˵���������
 *          ���Ϊ1˵���Ǹ��ڵ�
 *          ��Ŵ���1�� �����ż��˵�������� ����ҵ����׽���������  ����˵�����Һ��� �ҵ����׽���������
 *          ��ʱ��Ҫһ������ ����ס�����ĵ�ַ
 */

BTNode * createTree()
{
    BTNode * pT;
    elemType val;                                   // ���������
    int idx;                                        // ����ı��
    BTNode * arr[100];                              // �������� ��ס ���ĵ�ַ

    scanf("%d %d", &idx, &val);
    while (idx != 0)                                // ����Ǵ�1��ʼ�� ������Ϊ0  ���Ϊ0 ����
    {
        BTNode * pNew = (BTNode *) malloc(sizeof(BTNode));
        // ʡ���ж�pNew�Ƿ�Ϊ��
        pNew->data = val;
        pNew->pLChild = pNew->pRChild = NULL;
        arr[idx] = pNew;                            // ��ס ���ĵ�ַ

        if (idx == 1)                               // idx == 1 ˵�����������ĸ��ڵ�
        {
            pT = pNew;
        }
        else
        {
            int parent_idx = idx / 2;               // ���׽��ı��
            if (idx % 2 == 0)                       // ż��˵���� ����
            {
                arr[parent_idx]->pLChild = pNew;
            }
            else                                    // ����˵�����Һ���
            {
                arr[parent_idx]->pRChild = pNew;
            }
        }
        scanf("%d %d", &idx, &val);                 // ���� 0 0 ����
    }
    return pT;
}

// ����ݹ����������
// ͼ�⣺https://github.com/XerDemo/Algorithm-Tour/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95/Demo6_%E6%A0%91/image/Demo1_%E7%94%A8%E9%80%92%E5%BD%92%E5%85%88%E5%BA%8F%E9%81%8D%E5%8E%86%E4%BA%8C%E5%8F%89%E6%A0%91.png
void preOrderTraverse(BTNode * pT)
{
    // �ݹ�������� pT == NULL
    if (pT)                                        // ������
    {
        // ����˳�� �� �� ��  (D L R)
        printf("%d ", pT->data);                    // ��
        preOrderTraverse(pT->pLChild);              // ����������
        preOrderTraverse(pT->pRChild);              // ����������
    }
}

// ����ݹ����������  ����ݹ����ʽ�һ�һ��  ������һ���� ֻ��д����һ����
void inOrderTraverse(BTNode * pT)
{
    // �ݹ���� ���� pT == NULL
    if (pT == NULL)
    {
        return;
    }
    // �� �� �� (L D R)
    inOrderTraverse(pT->pLChild);
    printf("%d ", pT->data);
    inOrderTraverse(pT->pRChild);
}


// �ݹ�������
void postOrderTraverse(BTNode * pT)
{
    if (pT)
    {
        postOrderTraverse(pT->pLChild);
        postOrderTraverse(pT->pRChild);
        printf("%d ", pT->data);
    }
}

/*
 * ��α���  ����
 *   ����˼�룺 ���������ĸ��ڵ㿪ʼ �������Ϊ�� �����ڵ����
 *             ������в�Ϊ�� ����  ��ӡ����Ԫ�ص�ֵ
 *             �������Ԫ�����Ӳ�Ϊ�� ���  �Һ��Ӳ�Ϊ�� ���  ֱ������Ϊ��Ϊֹ
 */
void leverOrderTraverse(BTNode * pT)
{
    if (!pT)                                          // ��� ��Ϊ�� ֱ��return
    {
        return;
    }
    cycleQueue *pQ = createQueue();
    inQueue(pQ, pT);                                  // ��������
    // ֻҪ���в�Ϊ��
    while (!isEmpty(pQ))
    {
        BTNode *p = outQueue(pQ);
        printf("%d ", p->data);
        if (p->pLChild)                               // ���ڵ�����Ӳ�Ϊ�� ���
        {
            inQueue(pQ, p->pLChild);
        }
        if (p->pRChild)                               // ���ڵ���Һ��Ӳ�Ϊ�� ���
        {
            inQueue(pQ, p->pRChild);
        }
    }
    printf("\n");
}

/*
 *  �ݹ���Ҷ�ӽ���� �� Ҷ�ӽڵ���˭
 *     ����˼�룺�ڵݹ�����㷨��(�������򡢺��򡮲�ζ��У�������Ϊ��) �Ӹ��������  ������Һ��Ӷ�Ϊ��
 *
 */
void leafNum(BTNode * pT)
{
    // ��ע��ȥ���Ļ� ����ͳ��Ҷ�ӽ�����
    // static int count = 0;                              // ͳ��Ҷ�ӽ����� ��Ҫ����Ϊstatic
    if (pT)
    {
        // ������Һ��Ӷ�Ϊ��
        if (!pT->pLChild && !pT->pRChild)
        {
            // count++;                                   // Ҷ�ӽ���� + 1
            printf("%d ", pT->data);                      // ���Ҷ�ӽ��
        }
        leafNum(pT->pLChild);
        leafNum(pT->pRChild);
    }
    // return count;
}

/*
 *  ͳ�ƶ����� �ܽ����
 *      ����˼�룺 ������������Ϊ�� ������count++  ���ڵݹ�����㷨����
 *                �ݹ�ͳ������������� �ݹ�ͳ�������������
 */
int nodeNum(BTNode * pT)
{
    static int count = 0;                               // count ͳ�ƽ����
    if (pT)
    {
        count++;
        nodeNum(pT->pLChild);
        nodeNum(pT->pRChild);
    }

    return count;
}
/*
 * �ݹ�������������
 *    ����˼�룺 ��������Ϊ�� �򷵻�0
 *              ��Ϊ�� �ݹ�ͳ�������������   �ݹ�ͳ�������������
 *              �ݹ�������� �����������ֵ + 1 ��+1 ������ ���ڵ����ڵ���һ�㣩
 */
int treeDepth(BTNode * pT)
{
    int leftDepth, rightDepth, maxDepth;
    if (pT == NULL)                                    // ��Ϊ�� return 0
    {
        return 0;
    }
    leftDepth = treeDepth(pT->pLChild);                // �ݹ�������������
    rightDepth = treeDepth(pT->pRChild);               // �ݹ�������������
    maxDepth = leftDepth > rightDepth ? leftDepth : rightDepth; // ��������������� ����һ��
    return maxDepth + 1;                               // ������ + 1
}


/*******************************ѭ������******************************/
cycleQueue * createQueue()
{
    cycleQueue *pQ = (cycleQueue *) malloc(sizeof(cycleQueue));
    // ʡ���ж�pQ�Ƿ�Ϊ��
    pQ->front = pQ->rear = 0;
    return pQ;
}

int isFull(cycleQueue * pQ)
{
    return (pQ->rear + 1) % MAXSIZE == pQ->front;
}

int isEmpty(cycleQueue * pQ)
{
    return pQ->rear == pQ->front;
}

void inQueue(cycleQueue * pQ, BTNode * val)
{
    if (isFull(pQ))
    {
        printf("ѭ�������������ʧ�ܣ�\n");
        return;
    }
    pQ->rear = (pQ->rear + 1) % MAXSIZE;
    pQ->data[pQ->rear] = val;
}

BTNode * outQueue(cycleQueue * pQ)
{
    if (isEmpty(pQ))
    {
        printf("ѭ�����пգ�����ʧ�ܣ�\n");
        return NULL;
    }
    pQ->front = (pQ->front + 1) % MAXSIZE;
    return pQ->data[pQ->front];
}
