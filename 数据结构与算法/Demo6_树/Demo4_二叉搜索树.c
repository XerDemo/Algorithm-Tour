#include <stdio.h>
#include <stdlib.h>
/*
 * ������������
 *  1. ����������Ϊ�գ��������������н���ֵС�ڸ��ڵ��ֵ
 *  2. ����������Ϊ�գ� �������������еĽ���ֵ���ڸ��ڵ��ֵ
 *  3. ��������Ҳ���Ƕ���������
 *  4. һ���Ƕ�����
 *  5. һ����������ͬ�Ľ��
 *  6. �ص� ��������� ��С����
 */
typedef struct node{
    int data;
    struct node * leftChild;
    struct node * rightChild;
}BSTNode;

BSTNode * createTree();                                     // �ò�����ķ�ʽ��������������
BSTNode * insert(BSTNode * pT, int key);                    // ������
BSTNode * insert_recursion(BSTNode * pT, int key);          // �ݹ� ������
void deleteNode(BSTNode *pT, int key);                      // ɾ�����   3�����
BSTNode * search(BSTNode * pT, int key);                    // ���ҹؼ���key
BSTNode * search_recursion(BSTNode *pT, int key);           // �ݹ� ���ҹؼ��� key��λ��
BSTNode * findMax(BSTNode * pT);                            // ���Ҷ��������������ֵ   ���Ҷ�
BSTNode * findMax_recursion(BSTNode * pT);                  // �ݹ� ���Ҷ��������������ֵ   ���Ҷ�
BSTNode * findMin(BSTNode * pT);                            // ���Ҷ�������������Сֵ   �����
BSTNode * findMin_recursion(BSTNode * pT);                  // �ݹ� ���Ҷ�������������Сֵ   �����
void inorderTraverse(BSTNode * pT);                         // �����������������  ����

int main(void)
{
    BSTNode * pT = createTree();
    printf("���������");
    inorderTraverse(pT);

    printf("\n���ֵ��%d\n", findMax(pT)->data);
    printf("�ݹ����ֵ��%d\n", findMax_recursion(pT)->data);

    printf("��Сֵ��%d\n", findMin(pT)->data);
    printf("�ݹ���Сֵ��%d\n", findMin_recursion(pT)->data);

//    if (search(pT, 33))
//    {
//        printf("���ҳɹ���%d��λ�ã�%p\n", search(pT,33)->data, search(pT,33));
//    }
//    else
//    {
//        printf("����ʧ�ܣ�������33�����㣡\n");
//    }
//
//    if (search_recursion(pT, 33))
//    {
//        printf("�ݹ���ҳɹ���%d��λ�ã�%p\n", search_recursion(pT,33)->data, search_recursion(pT,33));
//    }
//    else
//    {
//        printf("�ݹ����ʧ�ܣ�������33�����㣡\n");
//    }

    deleteNode(pT, 9);
    inorderTraverse(pT);

    return 0;
}

// ����
BSTNode * createTree()
{
    BSTNode * pT = NULL;
    int key;

    printf("������ؼ���(����0):");
    scanf("%d", &key);

    while (0 != key)
    {
        // pT = insert(pT, key);                            // �ǵݹ�
        pT = insert_recursion(pT, key);                     // �ݹ�
        scanf("%d", &key);
    }
    return pT;
}

/*
 * ������  ���루��ǰ����
 *   ����˼�룺
 *      1.���������������ʱΪ�� �򽫲����㵱���µĸ��ڵ�
 *      2.�������������ǿ� ��������ʼ�� �����ֵ���ڸ���� �����ڵ��ұ���
 *                                  �����ֵС�ڸ��ڵ� �����ڵ������
 *                                  �����ֵ���ڸ��ڵ� ˵��֮ǰ������� ֵ ��������
 *                                  ֱ��Ϊ��NULL ��ʱ�ҵ���Ҫ�������ǰ�����
 *      3.���������ֵ����ǰ����� �ӵ� ǰ���ڵ���Һ�����   С��ǰ����� �ӵ�������
 */

BSTNode * insert(BSTNode * pT, int key)
{
    // pre��p��ǰ��
    BSTNode * p = NULL, *pre = NULL;
    BSTNode * pNew = (BSTNode * )malloc(sizeof(BSTNode));
    // ʡ���ж�pNew�Ƿ�Ϊ��
    pNew->data = key;
    pNew->leftChild = pNew->rightChild = NULL;

    // ����ǿ��� �������ڵ�
    if (NULL == pT)
    {
        pT = pNew;
    }
    else
    {   // ���ǿ���
        p = pT;
        // ��������ʼ�� keyӦ�÷�����
        while (p != NULL)
        {
            if (key > p->data)
            {
                pre = p;
                p = p->rightChild;
            } else if (key < p->data)
            {
                pre = p;
                p = p->leftChild;
            } else
            {
                printf("�˶����������Ѿ���%d\n", p->data);
                return pT;
            }
        }
        // ִ�е����� �Ѿ��ҵ���Ҫ�������ǰ�����
        // ���key������ǰ���ڵ� �ҵ�ǰ�������ұ�  ��֮
        if (key > pre->data)
        {
            pre->rightChild = pNew;
        } else
        {
            pre->leftChild = pNew;
        }
    }
    return pT;
}

/*
 * �ݹ� ������
 *    ͼ�⣺https://github.com/XerDemo/Algorithm-Tour/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%B8%8E%E7%AE%97%E6%B3%95/Demo6_%E6%A0%91/image/Demo3%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91-%E9%80%92%E5%BD%92%E6%8F%92%E5%85%A5%E5%9B%BE%E8%A7%A3.png
 */
BSTNode * insert_recursion(BSTNode * pT, int key)
{
    if (!pT)                                                             // ����ǿ��� �������ڵ�
    {
        pT = (BSTNode *) malloc(sizeof(BSTNode));
        pT->data = key;
        pT->rightChild = pT->leftChild = NULL;
    }
    else
    {         // ��Ҫ����Ԫ�ص�λ��
        if (key > pT->data)
        {
            pT->rightChild = insert_recursion(pT->rightChild, key);      // �ݹ����������
        }
        else if (key < pT->data)
        {
            pT->leftChild = insert_recursion(pT->leftChild, key);        // �ݹ����������
        }
        else
        {
            printf("key = %d �Ľ���Ѿ����ڣ�\n", key);
        }
    }
    return pT;
}




/*
 * ���ҹؼ��� key��λ��(��ַ)
 *    ����˼�룺��������ʼ�� ���key�ȸ��ڵ��data�� �����ڵ��ұ���
 *                        ���key�ȸ��ڵ��dataС �����ڵ������
 *                        ���key == ������data  �ҵ���
 *                        ���������������� �򲻴���key������
 */
BSTNode * search(BSTNode * pT, int key)
{
    BSTNode *p = pT;
    while (p)
    {
        if (key > p->data)
        {
            p = p->rightChild;
        }
        else if (key < p->data)
        {
            p = p->leftChild;
        }
        else     // key == p->data
        {
            return p;
        }
        /********************����һ��д��***************/
//        if (key == p->data)
//        {
//            return p;
//        }
//        p = key > p->data ? p->rightChild : p->leftChild;
    }
    // printf("û���ҵ���\n");
    return NULL;
}


BSTNode * search_recursion(BSTNode * pT, int key)
{
    // �ݹ��������  ����ʧ��
    if (pT == NULL)
    {
        return NULL;
    }

    if (key > pT->data)
    {
        return search_recursion(pT->rightChild, key);          // ���������еݹ����
    }
    else if (key < pT->data)
    {
        return search_recursion(pT->leftChild, key);           // ���������еݹ����
    }
    else
    {
        return pT;                                              // �ҵ���
    }
}


/*
 * �������ֵ��
 *     ����˼�룺һ·�Ӹ��ڵ����ұ߲� ֱ�� Ϊ��  ���ұ��Ǹ�����������ֵ
 */
BSTNode * findMax(BSTNode * pT)
{
    if (pT)
    {
        while (pT->rightChild)
        {
            pT = pT->rightChild;   // ���ҷ�֧һֱ���£�ֱ�����Ҷ˵�
        }
    }
    return pT;
}
// �������ֵ �ݹ�ⷨ
BSTNode * findMax_recursion(BSTNode * pT)
{
    if (pT == NULL)
    {
        return NULL;             // ������� ���� null
    }
    else if (!pT->rightChild)
    {
        return pT;               // ���������Ϊ�� ���� pT(���Ҷ˵�)
    }
    else
    {
        return findMax_recursion(pT->rightChild);  // ���ҷ�֧������
    }


}


/*
 * ������Сֵ��
 *     ����˼�룺һ·�Ӹ��ڵ�����߲� ֱ�� Ϊ��  ������Ǹ��������Сֵ
 */
BSTNode * findMin(BSTNode * pT)
{
    if (pT)
    {
        while (pT->leftChild)
        {
            pT = pT->leftChild;     // �����֧һֱ���£�ֱ������˵�
        }
    }
    return pT;
}

BSTNode * findMin_recursion(BSTNode * pT)
{
    if (pT == NULL)
    {
        return NULL;
    }
    else if (pT->leftChild == NULL)
    {
        return pT;
    }
    else
    {
        return findMin_recursion(pT->leftChild);
    }
}
/*
 * ɾ�����
 *    ����˼�룺
 *    * ɾ����� 3�����
 *    1.ɾ������Ҷ�ӽڵ�
 *        ���丸�ڵ��Ӧ��ָ���� ��ΪNULL
 *    2.ɾ���Ľ�� ֻ��һ����������������
 *        �������ĸ��ڵ�ȡ����ɾ�����
 *    3.ɾ���Ľ�� ��������������  ��2�ַ�����
 *        1������ֱ��ǰ����������ɾ���������������ֱ��ǰ����� ȡ��ɾ�����
 *        2������ֱ�Ӻ�̷�������ɾ���������������ֱ�Ӻ�̽�� ȡ��ɾ�����
 *        �ұ�ɾ�����ǰ�����ӱ�ɾ����������� һ·����  (��ɾ����������е����ֵ)
 *        �ұ�ɾ����ĺ�̣��ӱ�ɾ����������� һ·����  (��ɾ����������е���Сֵ)
 *           ��ɾ��
 *        L   D    R
 *   L D  R(ǰ��)   L D R(���)
 */

void deleteNode(BSTNode * pT, int key)
{
    // ���ҵ�Ҫɾ���Ľ��
    BSTNode *p = NULL, *pre = NULL, *child = NULL;
    p = pT;
    while (p)
    {
        if (key == p->data)
        {
            break;
        }
        pre = p;
        p = key > p->data ? p->rightChild : p->leftChild;
    }
    // ��ʱpָ����Ǵ�ɾ���Ľ���λ�� pre��p��ǰ��
    if (!p)
    {
        printf("û��������Ĵ���!\n");
        return;
    }
    // �����Ҷ�ڵ�  ���丸�ڵ��Ӧ��ָ���� ��ΪNULL(��ʱ��Ҫһ��ǰ�����pre����ס�丸�׽���λ��)
    if (p->leftChild == NULL && p->rightChild == NULL)
    {
        // Ҷ�ڵ��ڸ��ڵ�����
        if (pre->leftChild == p)
        {
            pre->leftChild = NULL;
        }
        else   // Ҷ�ڵ��ڸ��ڵ���ұ�
        {
            pre->rightChild = NULL;
        }
        free(p);
        p = NULL;
    }
    // ������Һ��Ӷ���Ϊ��
    else if (p->leftChild!=NULL && p->rightChild!=NULL)
    {
        // pTemp��ŵ��Ǵ�ɾ������λ��
        BSTNode * pTemp = p;
        // ��������������˵�
        for (pre = pTemp, p = pTemp->rightChild; p->leftChild; pre = p, p = p->leftChild);
        // ��ʱp���������ֱ�Ӻ�����㣨��ɾ�����������������˵㣬Ҳ���Ǵ�ɾ���������������Сֵ�� pre����ǰ�����
        pTemp->data = p->data;                   // �������ǰ�����ȡ����ɾ�����  ֻ����������� ��Ҫ��p�ĺ�����
        // ��pȡ����ɾ�����ʱ ��p�ڸ��׽���Ӧ��ָ������ΪNULL
        if (pre->leftChild == p)
        {
            pre->leftChild = NULL;
        }
        else
        {
            pre->rightChild = NULL;
        }
    }
    // ���ֻ��������Ϊ�� �� ֻ��������Ϊ��
    else
    {
        // ��ʱ��Ҫchildָ���ɾ������Ψһһ������
        child = p->leftChild ? p->leftChild : p->rightChild;
        // ����ɾ�������������������� �ҵ��丸�ڵ��Ӧ��ָ����
        if (pre->leftChild == p)
        {
            pre->leftChild = child;
        }
        else
        {
            pre->rightChild = child;
        }
        free(p);
        p = NULL;
    }
    // �Ż� ���Խ����������Ӧ���丸�׽���ָ�����ֵͳһд��if else if else����
}


// �������
void inorderTraverse(BSTNode * pT)
{
    // ���������
    if (pT)
    {
        inorderTraverse(pT->leftChild);             // �ݹ����������
        printf("%d   ", pT->data);                  // �������ڵ�
        inorderTraverse(pT->rightChild);            // �ݹ����������
    }
}

