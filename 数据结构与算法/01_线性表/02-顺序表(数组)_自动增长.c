/**
 * 顺序表 __（数组）
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5                                      // 初始数组容量  可以通过realloc来增长
#define INCREAMENT 5                                   // 增长因子 每次增长5个空间

typedef struct
{
    int *data;                                        // 数组空间基址
    int maxsize;                                      // 数组大小
    int last;                                          // 指向数组最后一个元素的下标  初始时为空：-1  有一个元素：0 以此类推
} seqList;


seqList *createSeqList();                              // 初始化方式2：在堆中分配  (此处选用在“堆”中分配)
int insertSeqList(seqList *pL, int pos, int val);      // 插入
int deleteSeqList(seqList *pL, int pos, int *pVal);    // 删除
int emptySeqList(seqList *pL);                         // 判断顺序表是否空
int fullSeqList(seqList *pL);                          // 判断顺序表是否满
void traverse(seqList *pL);                            // 遍历
int lengthSeqList(seqList *pL);                        // 顺序表长度
void sortSeqList(seqList *pL);                         // 排序 从小到大
void reverseSeqList(seqList *pL);                      // 倒置
void appendSeqList(seqList *pL, int val);              // 追加
int findSeqList(seqList *pL, int val);                 // 找到元素val在数组中的下标 -1代表没找到
int getSeqList(seqList *pL, int pos);                  // 返回第pos个位置的元素
int previewSeqList_1(seqList *pL, int val);            // 返回val的前驱  -1:没有前驱
int previewSeqList_2(seqList *pL, int val);            // 返回val的前驱  -1:没有前驱
int nextSeqList_1(seqList *pL, int val);               // 返回val的后续  -1:没有后续
int nextSeqList_2(seqList *pL, int val);               // 返回val的后续  -1:没有后续

int main(void)
{
    int val;
    // 初始话方式2： 使用 malloc  在（堆）  "挖坑"  malloc需要头文件 stdlib.h
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

    printf("99在数组下标：%d\n", findSeqList(pL, 99));

    printf("lenght is : %d\n", lengthSeqList(pL));

    printf("第4个元素是：%d\n", getSeqList(pL, 4));

    printf("5的前驱：%d\n", previewSeqList_1(pL, 5));
    printf("4的前驱：%d\n", previewSeqList_1(pL, 4));
    printf("5的前驱：%d\n", previewSeqList_2(pL, 5));
    printf("4的前驱：%d\n", previewSeqList_2(pL, 4));

    printf("5的后续：%d\n", nextSeqList_1(pL, 5));
    printf("100的后续：%d\n", nextSeqList_1(pL, 100));
    printf("5的后续：%d\n", nextSeqList_2(pL, 5));
    printf("100的后续：%d\n", nextSeqList_2(pL, 100));
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
    pL->last = -1;      // 初始化为 -1
    return pL;          // pL在栈中分配   (seqList *) malloc(sizeof(seqList))在堆中分配  栈中分配的pL会在createSeqList结束后释放 因此需要返回 堆中的地址需要程序员手动释放
}

int emptySeqList(seqList *pL)
{
    // return pL->last == -1 ;  不推荐此种写法 如果 == 写成了 = 就变成了给last赋值-1 程序不会报错
    return -1 == pL->last;     // 如果 == 写成了 = 变量不可能赋值给常量 程序会报错
}

int fullSeqList(seqList *pL)
{
    return MAXSIZE - 1 == pL->last;
}

// -1：满    0：位置不合法     1：插入成功     在调用insertSeqList的函数里判断
int insertSeqList(seqList *pL, int pos, int val)
{
    int i;
    if (fullSeqList(pL))
    {
        //暂时的  利用realloc函数扩大内存 在赋值给pL->data;
        int *pTemp = (int *) realloc(pL->data, sizeof(int) * (pL->maxsize + INCREAMENT));
        pL->data = pTemp;
        pL->maxsize = pL->maxsize + INCREAMENT;
    }
    // 1<=pos<=last+2  合法状态  判断插入位置是否合法
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
    // 合法位置  1<=pos<=last+1
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
//    *pVal = pL->data[pos-1];   必须写在for（）上面
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
                // 用 异或排序
                pL->data[j] = pL->data[j] ^ pL->data[j + 1];
                pL->data[j + 1] = pL->data[j] ^ pL->data[j + 1];
                pL->data[j] = pL->data[j] ^ pL->data[j + 1];
                // 用 中间变量
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
        // 交换
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
        //暂时的  利用realloc函数扩大内存 在赋值给pL->data;
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
    // 合法位置 1<= pos <= last + 1
    if (pos < 1 || pos > pL->last + 1)
    {
        printf("getSeqList pos is illeage!\n");
        return 0;
    }
    return pL->data[pos - 1];
}

int previewSeqList_1(seqList *pL, int val)
{
    int pos = findSeqList(pL, val);                             // pos = val的数组下标
    if (pos != 0)
    {
        return pL->data[pos - 1];
    }
    return -1;
}

int previewSeqList_2(seqList *pL, int val)
{
    // 从数组下标为1的地方开始找 下标为0的元素没有前驱
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
    int pos = findSeqList(pL, val);                             // pos = val的数组下标
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



