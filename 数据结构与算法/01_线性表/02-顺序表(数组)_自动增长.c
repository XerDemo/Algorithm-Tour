/**
 * ˳��� __�����飩
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5                                      // ��ʼ��������  ����ͨ��realloc������
#define INCREAMENT 5                                   // �������� ÿ������5���ռ�

typedef struct
{
    int *data;                                        // ����ռ��ַ
    int maxsize;                                      // �����С
    int last;                                          // ָ���������һ��Ԫ�ص��±�  ��ʼʱΪ�գ�-1  ��һ��Ԫ�أ�0 �Դ�����
} seqList;


seqList *createSeqList();                              // ��ʼ����ʽ2���ڶ��з���  (�˴�ѡ���ڡ��ѡ��з���)
int insertSeqList(seqList *pL, int pos, int val);      // ����
int deleteSeqList(seqList *pL, int pos, int *pVal);    // ɾ��
int emptySeqList(seqList *pL);                         // �ж�˳����Ƿ��
int fullSeqList(seqList *pL);                          // �ж�˳����Ƿ���
void traverse(seqList *pL);                            // ����
int lengthSeqList(seqList *pL);                        // ˳�����
void sortSeqList(seqList *pL);                         // ���� ��С����
void reverseSeqList(seqList *pL);                      // ����
void appendSeqList(seqList *pL, int val);              // ׷��
int findSeqList(seqList *pL, int val);                 // �ҵ�Ԫ��val�������е��±� -1����û�ҵ�
int getSeqList(seqList *pL, int pos);                  // ���ص�pos��λ�õ�Ԫ��
int previewSeqList_1(seqList *pL, int val);            // ����val��ǰ��  -1:û��ǰ��
int previewSeqList_2(seqList *pL, int val);            // ����val��ǰ��  -1:û��ǰ��
int nextSeqList_1(seqList *pL, int val);               // ����val�ĺ���  -1:û�к���
int nextSeqList_2(seqList *pL, int val);               // ����val�ĺ���  -1:û�к���

int main(void)
{
    int val;
    // ��ʼ����ʽ2�� ʹ�� malloc  �ڣ��ѣ�  "�ڿ�"  malloc��Ҫͷ�ļ� stdlib.h
    seqList *pL = createSeqList();

    insertSeqList(pL, 1, 5);
    insertSeqList(pL, 2, 4);
    insertSeqList(pL, 3, 3);
    insertSeqList(pL, 4, 1);
//    deleteSeqList(pL,2,&val);
//    deleteSeqList(pL,3,&val);
    appendSeqList(pL, 88);
    appendSeqList(pL, 99);
    appendSeqList(pL, 100);

    printf("99�������±꣺%d\n", findSeqList(pL, 99));

    printf("lenght is : %d\n", lengthSeqList(pL));

    printf("��4��Ԫ���ǣ�%d\n", getSeqList(pL, 4));

    printf("5��ǰ����%d\n", previewSeqList_1(pL, 5));
    printf("4��ǰ����%d\n", previewSeqList_1(pL, 4));
    printf("5��ǰ����%d\n", previewSeqList_2(pL, 5));
    printf("4��ǰ����%d\n", previewSeqList_2(pL, 4));

    printf("5�ĺ�����%d\n", nextSeqList_1(pL, 5));
    printf("100�ĺ�����%d\n", nextSeqList_1(pL, 100));
    printf("5�ĺ�����%d\n", nextSeqList_2(pL, 5));
    printf("100�ĺ�����%d\n", nextSeqList_2(pL, 100));
    traverse(pL);

    printf("After sortSeqList\n");
    sortSeqList(pL);
    traverse(pL);

    printf("After reverseSeqList\n");
    reverseSeqList(pL);
    traverse(pL);
    printf("lenght is : %d\n", lengthSeqList(pL));

    return 0;

}


seqList *createSeqList()
{
    seqList *pL = (seqList *) malloc(sizeof(seqList));
    pL->data = (int *) malloc(sizeof(int) * MAXSIZE);
    pL->maxsize = MAXSIZE;
    pL->last = -1;      // ��ʼ��Ϊ -1
    return pL;          // pL��ջ�з���   (seqList *) malloc(sizeof(seqList))�ڶ��з���  ջ�з����pL����createSeqList�������ͷ� �����Ҫ���� ���еĵ�ַ��Ҫ����Ա�ֶ��ͷ�
}

int emptySeqList(seqList *pL)
{
    // return pL->last == -1 ;  ���Ƽ�����д�� ��� == д���� = �ͱ���˸�last��ֵ-1 ���򲻻ᱨ��
    return -1 == pL->last;     // ��� == д���� = ���������ܸ�ֵ������ ����ᱨ��
}

int fullSeqList(seqList *pL)
{
    return MAXSIZE - 1 == pL->last;
}

// -1����    0��λ�ò��Ϸ�     1������ɹ�     �ڵ���insertSeqList�ĺ������ж�
int insertSeqList(seqList *pL, int pos, int val)
{
    int i;
    if (fullSeqList(pL))
    {
        //��ʱ��  ����realloc���������ڴ� �ڸ�ֵ��pL->data;
        int *pTemp = (int *) realloc(pL->data, sizeof(int) * (pL->maxsize + INCREAMENT));
        pL->data = pTemp;
        pL->maxsize = pL->maxsize + INCREAMENT;
    }
    // 1<=pos<=last+2  �Ϸ�״̬  �жϲ���λ���Ƿ�Ϸ�
    if (pos < 1 || pos > pL->last + 2)
    {
        printf("insert pos is illegal!\n ");
        return 0;
    }

    for (i = pL->last; i >= pos - 1; --i)
    {
        pL->data[i + 1] = pL->data[i];
    }
    pL->data[pos - 1] = val;
    pL->last++;
    return 1;
}

int deleteSeqList(seqList *pL, int pos, int *pVal)
{
    int i;
    if (emptySeqList(pL))
    {
        printf("seqList is empty!\n");
        return -1;
    }
    // �Ϸ�λ��  1<=pos<=last+1
    if (pos < 1 || pos > pL->last + 1)
    {
        printf("delete pos is illegal!\n ");
        return 0;
    }

    *pVal = pL->data[pos - 1];
    for (i = pos; i <= pL->last; ++i)
    {
        pL->data[i - 1] = pL->data[i];
    }
//    *pVal = pL->data[pos-1];   ����д��for��������
    pL->last--;
    return 1;
}

int lengthSeqList(seqList *pL)
{
    return pL->last + 1;
}

void sortSeqList(seqList *pL)
{
    int flag = 1;
    int i, j;
    for (i = 0; i < pL->last; ++i)
    {
        flag = 1;
        for (j = 0; j < pL->last - i; ++j)
        {
            if (pL->data[j] > pL->data[j + 1])
            {
                // �� �������
                pL->data[j] = pL->data[j] ^ pL->data[j + 1];
                pL->data[j + 1] = pL->data[j] ^ pL->data[j + 1];
                pL->data[j] = pL->data[j] ^ pL->data[j + 1];
                // �� �м����
//               int temp = pL->data[j];
//               pL->data[j] = pL->data[j+1];
//               pL->data[j+1] = temp;
                flag = 0;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
}

void reverseSeqList(seqList *pL)
{
    int i = 0;
    int j = pL->last;
    while (i < j)
    {
        // ����
        pL->data[i] = pL->data[i] ^ pL->data[j];
        pL->data[j] = pL->data[i] ^ pL->data[j];
        pL->data[i] = pL->data[i] ^ pL->data[j];
        i++;
        j--;
    }
}

void appendSeqList(seqList *pL, int val)
{
    if (fullSeqList(pL))
    {
        //��ʱ��  ����realloc���������ڴ� �ڸ�ֵ��pL->data;
        int *pTemp = (int *) realloc(pL->data, sizeof(int) * (pL->maxsize + INCREAMENT));
        pL->data = pTemp;
        pL->maxsize = pL->maxsize + INCREAMENT;
    }
    pL->data[++pL->last] = val;
}

int findSeqList(seqList *pL, int val)
{
    int i;
    for (i = 0; i <= pL->last; ++i)
    {
        if (pL->data[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int getSeqList(seqList *pL, int pos)
{
    if (emptySeqList(pL))
    {
        printf("seqList is empty!\n");
        return -1;
    }
    // �Ϸ�λ�� 1<= pos <= last + 1
    if (pos < 1 || pos > pL->last + 1)
    {
        printf("getSeqList pos is illeage!\n");
        return 0;
    }
    return pL->data[pos - 1];
}

int previewSeqList_1(seqList *pL, int val)
{
    int pos = findSeqList(pL, val);                             // pos = val�������±�
    if (pos != 0)
    {
        return pL->data[pos - 1];
    }
    return -1;
}

int previewSeqList_2(seqList *pL, int val)
{
    // �������±�Ϊ1�ĵط���ʼ�� �±�Ϊ0��Ԫ��û��ǰ��
    int i = 1;
    while (i <= pL->last && val != pL->data[i])
    {
        i++;
    }
    if (i > pL->last)
    {
        return -1;
    }
    return pL->data[i - 1];
}

int nextSeqList_1(seqList *pL, int val)
{
    int pos = findSeqList(pL, val);                             // pos = val�������±�
    if (pos != pL->last)
    {
        return pL->data[pos + 1];
    }
    return -1;
}

int nextSeqList_2(seqList *pL, int val)
{
    int i = 0;
    while (i < pL->last && val != pL->data[i])
    {
        i++;
    }
    if (i == pL->last)
    {
        return -1;
    }
    return pL->data[i + 1];
}

void traverse(seqList *pL)
{
    int i;
    if (emptySeqList(pL))
    {
        printf("seqList is empty!\n");
        return;
    }
    printf("seqList is : ");
    for (i = 0; i <= pL->last; ++i)
    {
        printf(" %d ", pL->data[i]);
    }
    printf("\n");
}



