#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 256                                           // 用户输入的字符串最大的长度
/**
 * 定长顺序串 的基本操作
 */
typedef struct
{
    char arr[MAXSIZE];                                        // 定义数组
    int length;                                               // 字符数组的实际的长度
} Str;

void initStr(Str *pS);                                        // 初始化

int lenStr(Str *S);                                           // 字符串的长度

void concatStr(Str *S1, Str *S2);                             // 连接两个字符串

void SubStr(Str *S, int pos, int len, Str *sub);              // 求子串  在给定串S中的第pos个位置，截取len个字符串构成子串 sub

int equalStr(Str *S1, Str *S2);                               // 比较 S1 和 S2的大小

int insertStr(Str *S, int pos, Str *S1);                      // 在字符串S中的第pos个位置前插入子串S1

int deleteStr(Str *S, int pos, int len);                      // 删除串S从第pos个位置起 len个元素

int indexStr(Str *S, Str *S1, int pos);                       // 查找 子串S1 在 S中第pos个位置后 出现的位置

int main(void)
{
    Str S1;
    initStr(&S1);
    puts(S1.arr);
    printf("S1 length is : %d\n", S1.length);

    printf("------------------\n");

    Str S2;
    initStr(&S2);
    puts(S2.arr);
    printf("S2 length is : %d\n", S2.length);


    printf("-------indexStr--------\n");
    printf("S1 在 S2 中 出现的位置：%d\n", indexStr(&S2, &S1, 1));

//    printf("------deleteStr-----\n");
//    deleteStr(&S2, 2, 3);
//    puts(S2.arr);
//    printf("S2 length is : %d\n", S2.length);

//    printf("-------concatStr-------\n");
//    concatStr(&S1, &S2);
//    printf("S1 length is : %d\n", S1.length);
//    puts(S1.arr);
//
//    Str S3;
//    printf("---------SubStr--------\n");
//    SubStr(&S2, 2, 4, &S3);
//    puts(S3.arr);
//    printf("S3 length is : %d\n", S3.length);
//
//    printf("---------equalStr--------\n");
//    if (equalStr(&S1, &S2) > 0)
//    {
//        printf("S1 > s2\n");
//    } else if (equalStr(&S1, &S2) == 0)
//    {
//        printf("S1 == S2\n");
//    } else
//    {
//        printf("S1 < S2\n");
//    }

//    printf("---------insertStr--------\n");
//
//    insertStr(&S2, 4, &S1);
//    puts(S2.arr);
//    printf("S2 length is : %d\n", S2.length);


    return 0;
}




void initStr(Str *pS)
{
    char a[MAXSIZE];                                             // 记录用户输入的字符串
    gets(a);
    // i:用户输入字符串的个数
    int i = 0;
    while (a[i] != '\0')
    {
        i++;
    }

    int j;
    // 注意此处将'\0'结束标也copy过来了
    for (j = 0; j <= i; ++j)
    {
        pS->arr[j] = a[j];
    }
    pS->length = i;
}


int lenStr(Str *S)
{
    int i = 0;
    while (S->arr[i] != '\0')
    {
        i++;
    }
    return i;
}

void concatStr(Str *S1, Str *S2)
{
    if (S1->length + S2->length > MAXSIZE)
    {
        printf("S1和S2连接在一起超出了MAXSIZE， 溢出！\n");
        return;
    }
    int i;
    for (i = 0; i < S2->length; ++i)
    {
        S1->arr[S1->length + i] = S2->arr[i];         // 串S2 连接到串S1的后面
    }
    S1->length = S1->length + S2->length;           // 连接后S1的长度
}

// 求子串  在给定串S中的第pos个位置，截取len个字符串构成子串 sub
void SubStr(Str *S, int pos, int len, Str *sub)
{
    // 1 <= pos <= S->length     截取的个数len要 >0   但是len又不能超出数组能截取最大的界限
    if (pos < 1 || pos > S->length || len < 0 || pos + len - 1 > S->length)
    {
        printf("插入位置 或 截取长度 不合法！\n");
        return;
    }
    int i, k;                                    // i：是S截取时候的起始索引   k：是子串的起始索引
    for (i = pos - 1, k = 0; k < len; ++i, ++k)
    {
        sub->arr[k] = S->arr[i];                // 逐个将S从pos起len个元素复制到子串
    }
    sub->arr[k + 1] = '\0';                     // 子串加上 '\0'结束标志
    sub->length = len;                          // 子串的长度
}

// 串比较 两个串的长度先等且对应位置上的字符相同时，才相等
int equalStr(Str *S1, Str *S2)
{
    int i;
    // S1->arr[i] 当i++ S1走到'\0'时， 结束循环  S2->arr[i]同理   '\0'在内存中 <==> NULL <==> 0
    while (S1->arr[i] == S2->arr[i] && S1->arr[i] && S2->arr[i])
    {
        i++;
    }
    return S1->arr[i] - S2->arr[i];            // >0:S1大  ==0：S1和S2相等   <0:S1小
}

// 在字符串S中的第pos个位置前插入子串S1
int insertStr(Str *S, int pos, Str *S1)
{
    // 合法位置  1 <=pos <= S->length+1     S->length + S1->length <= MAXSIZE
    if (pos < 1 || pos > S->length + 1 || S->length + S1->length > MAXSIZE)
    {
        printf("插入位置错误! \n");
        return -1;
    }
    // 将S串的元素下标从S->length - 1到pos - 1的元素往后移动S1->length 个位置
    int i;
    for (i = S->length - 1; i >= pos - 1; --i)
    {
        S->arr[S1->length + i] = S->arr[i];
    }

    // j:S中pos个位置的下标   k：S1中元素的起始下标  将S1的值复制到S
    int j, k;
    for (j = pos - 1, k = 0; k < S1->length; ++j, ++k)
    {
        S->arr[j] = S1->arr[k];
    }
    S->length = S->length + S1->length;
    S->arr[S->length] = '\0';                 // 如果时在S1的末尾插入子串  则要加 '\0'结束标志
    return 1;
}


// 删除串S从第pos个位置起 len个元素
int deleteStr(Str *S, int pos, int len)
{
    // 合法位置  1 <= pos <= S->length   len >0   pos+len-1 <= S->length
    if (pos < 1 || pos > S->length || len < 0 || pos + len - 1 > S->length)
    {
        printf("删除位置不合法！\n");
        return -1;
    }
    // i：要删除元素的起始元素的索引   k：要删除元素 + len 元素所对应的下标 将索引为k的元素移到i位置
    int i, k;
    for (i = pos - 1, k = pos + len - 1; k < S->length; ++i, ++k)
    {
        S->arr[i] = S->arr[k];
    }
    // 注意此处是在 索引为i的位置 加上'\0'结束标志
    S->arr[i] = '\0';
    // 更新删除后数组的长度
    S->length = S->length - len;
    return 1;
}

// 查找 子串S1 在 S中第pos个位置后 出现的位置
int indexStr(Str *S, Str *S1, int pos)
{
    int i, j;
    // 如果位置合法
    if (1 <= pos && pos <= S->length)
    {
        // i：是S起始位置  j：子串S1的起始位置
        i = pos - 1;
        j = 0;
        while (i < S->length && j < S1->length)
        {
            // 当两者对应下标元素相等  两者都往后移
            if (S->arr[i] == S1->arr[j])
            {
                i++;
                j++;
            }
            else   // 如果不想等
            {
                // 串S退回到i-j+1的位置  画个图就知道了  串S1的索引从0开始
                i = i - j + 1;
                j = 0;
            }
        }
        // 退出while循环  当j>=S1->length 即子串S1遍历到'\0'的位置
        if (j >= S1->length)
        {
            return i - S1->length + 1;     // 返回值 画个图就知道了
        } else
        {
            return -1;
        }
    }
    return -1;
}