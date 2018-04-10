#include <stdio.h>
#include <stdlib.h>

/**
    2018/4/6/17��34��
    ����Ļ���ʵ��  ��ͷ�ڵ�
    ��ͼ��������ĸ��ֲ���ԭ���ܼ�
    pHead ͷָ��   pHead-> ͷ���   pHead->pNext   �׽ڵ�
    ���� ɾ�� ������֪����ǰ��
    ����malloc free �ο����ϣ� http://itopic.org/c-malloc-free.html
    �������ݣ� 1 2 3 4 5 -1
 */
typedef struct Node
{
    int data;                                               // ������
    struct Node *pNext;                                    // ָ����
} LinkNode, *LinkList;                                      // LinkNode�ȼ��� struct Node �� LinkList�ȼ��� struct Node *

LinkNode *createLinkList();                                // ��������
void traverse(LinkNode *pHead);                            // ����
int emptyLinkList(LinkNode *pHead);                        // �ж������Ƿ�Ϊ��
int lengthLinkList(LinkNode *pHead);                       // ��������ĳ���
LinkNode *findLinkList(LinkNode *pHead, int val);          // ����Ԫ��val�������е�λ��  �������ַ Ϊ�˷������ɾ��
LinkNode *searchLinkList(LinkNode *pHead, int pos);        // ���ҵ�pos��λ�� ��Ӧ�����λ�� �������ɾ��
int insertLinkList_1(LinkNode *pHead, int pos, int val);   // ����  ��� searchLinkListʹ��
int insertLinkList_2(LinkNode *pHead, int pos, int val);   // ����  ��ʵ���ǽ�searchLinkList + insertLinkList_1���
int deleteLinkList_1(LinkNode *pHead, int pos, int *pVal); // ɾ��  ��� searchLinkListʹ��
int deleteLinkList_2(LinkNode *pHead, int pos, int *pVal); // ɾ��  ��ʵ���ǽ�searchLinkList + deleteLinkList_1���
int deleteLinkList_3(LinkNode *pHead, int val);            // ɾ��  ���� Ԫ�ص�ֵ ��ɾ��

int main(void)
{
    int val;
    LinkNode *pHead = createLinkList();
    printf("LinkList length is : %d\n", lengthLinkList(pHead));

    insertLinkList_1(pHead, 1, 99);
    insertLinkList_2(pHead, 3, 88);
    traverse(pHead);

    if (deleteLinkList_1(pHead, 7, &val))
    {
        printf("delete: %d \n", val);
    }
    if (deleteLinkList_2(pHead, 1, &val))
    {
        printf("delete: %d \n", val);
    }
    // ������� val=2 ɾ���� 2
    deleteLinkList_3(pHead, 2);

    traverse(pHead);
    printf("LinkList length is : %d\n", lengthLinkList(pHead));
    return 0;
}

LinkNode *createLinkList()
{
    int x;                                              // ���������   -1�������
    LinkNode *pHead = (LinkNode *) malloc(sizeof(LinkNode));
    if (!pHead)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    LinkNode *pTail = pHead;
    pTail->pNext = NULL;

    printf("����������(�ո������-1����)��\n");
    scanf("%d", &x);
    while (-1 != x)
    {
        LinkNode *pNew = (LinkNode *) malloc(sizeof(LinkNode));
        // ��ʡ���ж� pNew�Ƿ�Ϊ��
        pNew->data = x;
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pNew;
        scanf("%d", &x);
    }
    return pHead;
}

int emptyLinkList(LinkNode *pHead)
{
    return pHead->pNext == NULL;
}

LinkNode *findLinkList(LinkNode *pHead, int val)
{
    LinkNode *p = pHead->pNext;                    // pָ���׽ڵ� ����һ����Ч���ݵĽڵ㣩
    while (p != NULL && val != p->data)
    {
        p = p->pNext;
    }
    // ��д������ ��p==NULL  p->data �ᱨ��  NULL->data ���Դ���
//    if (val == p->data)
//    {
//        return p;
//    } else{
//        return NULL;
//    }
    return p;
}

// ���ո�����pos��λ�� �������� �� ��Ӧ��Ԫ��    ���� NULL ˵��û��
LinkNode *searchLinkList(LinkNode *pHead, int pos)
{
    int i = 0;                                          // �����Ǵ�i=0 ͷ�ڵ�  i=1 �׽ڵ�.......����  Ϊʲô����i=1��ʼ ���insertLinkList_1��֪����
    LinkNode *p = pHead;
    while (p != NULL && i < pos)
    {
        p = p->pNext;
        i++;
    }
    // �����е���һ��  ˵�� p == NULL || i == pos
    if (pos == i)
    {
        return p;
    } else
    {
        return NULL;
    }
}

int lengthLinkList(LinkNode *pHead)
{
    int i;
    LinkNode *p = pHead->pNext;
    while (p != NULL)
    {
        i++;
        p = p->pNext;
    }
    return i;
}

int insertLinkList_1(LinkNode *pHead, int pos, int val)
{
    // ��pos = 1ʱ pΪ��0��Ԫ��Ҳ����ͷ�ڵ� ���searchLinkList��i�Ǵ�1��ʼ ���������Բ��� ȴ���ص���NULL
    LinkNode *p = searchLinkList(pHead, pos - 1);                           // p��p��posԪ�ص�ǰ��
    // ���ǰ���ڵ�ĵ�ַΪ�� ˵�� �������
    if (p == NULL)
    {
        printf("insertLinkList_1 is failed!\n");
        return 0;
    } else
    {
        LinkNode *pNew = (LinkNode *) malloc(sizeof(LinkNode));
        pNew->data = val;
        pNew->pNext = p->pNext;
        p->pNext = pNew;
        return 1;
    }
}

int insertLinkList_2(LinkNode *pHead, int pos, int val)
{
    int i = 0;
    LinkNode *p = pHead;                // ��ͷ�ڵ㿪ʼ
    while (p != NULL && i < pos - 1)
    {
        p = p->pNext;
        ++i;
    }
    //�˳�whileѭ�� ֻ�����ֿ��� 1.p==NULL  2.i >= pos-1(�����ֿ�������i==pos-1�����������Ҫ�ҵĵ�pos-1���ڵ㣬 ����һ��i>pos-1,������� ֱ��0)
    if (p == NULL || i > pos - 1)
    {
        return 0;
    } else
    {                     // pos - 1 == i   ����p �Ѿ���pos��ǰ���ڵ�
        LinkNode *pNew = (LinkNode *) malloc(sizeof(LinkNode));
        //ʡ���ж�pNew�Ƿ�Ϊ��
        pNew->data = val;
        pNew->pNext = p->pNext;
        p->pNext = pNew;
        return 1;
    }
}

int deleteLinkList_1(LinkNode *pHead, int pos, int *pVal)
{
    LinkNode *p = searchLinkList(pHead, pos - 1);              // pΪ ��pos��Ԫ�ص�ǰ��
    if (p == NULL)
    {
        printf("deleteLinkList_1 is failed!\n");
        return 0;
    }
    LinkNode *pTemp = p->pNext;
    *pVal = pTemp->data;
    p->pNext = pTemp->pNext;
    free(pTemp);                                               // pTemp ��ָ����ڴ汻�ͷ�(��)     ָ�����pTemp������ĵ�ַ��û�б��ͷ�(ջ)
    pTemp = NULL;                                              // ��Ȼʹ��free����֮��ָ�����pTemp������ĵ�ַ��û�иı䣬�����Ǿ���Ҫ���°�pTemp��ֵ��ΪNULL(������Ϊ��Ұָ�롱)
    return 1;
}

int deleteLinkList_2(LinkNode *pHead, int pos, int *pVal)
{
    int i = 0;
    LinkNode *p = pHead;                   // ��ͷ�ڵ㿪ʼ
    // ��������ﲻͬ���� ����ֻҪ��ͷ�ڵ� �����ڵ�һ����Чλ�ò��� ɾ����ͬ ���û����ЧԪ������ɾ��
    while (p->pNext != NULL && i < pos - 1)
    {
        p = p->pNext;
        ++i;
    }
    if (p->pNext == NULL || i > pos - 1)
    {
        return 0;
    } else
    {
        LinkNode *pTemp = p->pNext;
        *pVal = pTemp->data;
        p->pNext = pTemp->pNext;
        free(pTemp);
        pTemp = NULL;
        return 1;
    }
}

int deleteLinkList_3(LinkNode *pHead, int val)
{
    LinkNode *p = pHead->pNext;           // ���׽ڵ㿪ʼ  Ҳ���Դ�ͷ�ڵ㿪ʼ  ��ô���θ�Ϊp = pHead    p->pNext != NULL   p->pNext = NULL
    LinkNode *q = NULL;                   // ��������p��ǰ��
    while (p != NULL && val != p->data)
    {
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
    {
        return -1;
    } else
    {
        q->pNext = p->pNext;
        free(p);
        p = NULL;
        return 1;
    }

}

void traverse(LinkNode *pHead)
{
    if (emptyLinkList(pHead))
    {
        printf("LinkList is empty!\n");
        return;
    }
    printf("LinkList is : ");
    LinkNode *p = pHead->pNext;
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}


