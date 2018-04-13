#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define LEN 6

/**
 *  计算器的简单实现 + - * / % （）
 *  只能实现一位数 
 */

typedef struct stack
{
    float data[MAXSIZE];                                          // 操作数数组
    char operation[MAXSIZE];                                      // 运算符数组
    int top1;                                                     // 操作数栈顶指针
    int top2;                                                     // 运算符栈顶指针
} seqStack;

seqStack *createStack();                                          // 初始化
void push(seqStack *ps, float val, int flag);                     // 入栈  flag == 1 入操作数栈   反之 入运算符栈
float pop(seqStack *pS, int flag);                                // 出栈  flag == 1 出操作数栈   反之 出运算符栈
void traverse(seqStack *pS, int flag);                            // 遍历
int compareOrder(char operator[LEN], int operator_order[LEN][LEN], char op1, char  op2); // 返回op2 与op1的优先级大小
void do_oprator(seqStack *pS, char op2);                                                 // 根据运算符op2，在操作数取两个数做运算

int main(void)
{
//    "9*9%3+(((5+4*5)+9)-2)#"
//    "(4*3)*1+2+(4*3)#"
    seqStack * pS =createStack();
    char input[100] ="(4*3)*1+2+(4*3)#" ;              // 输入的表达式
    // gets(input);                                          // '#' 结束标志 用户可以输入
    char *p = input;                                         // 指针p指向该字符数组 通过p的移动来处理  遇到的字符
    // 运算符数组 未进栈之前 '('的优先级最高，进栈之后'('的优先级最低 ,遇到')'栈内元素弹出到'('结束为止， 待进栈的运算符优先级高于栈内运算符才进栈，小于等于栈内元素出栈 运算符出栈一个 操作数出栈两个
    char operator[LEN] = {'+', '-', '*', '/', '(', '%'};     // 比如比较带入栈运算符 * ，栈顶元算符+,在operator中'+':0   在operator中'*':2  然后到operator_order找[0][2]为1，op1优先级高
    // 优先级数组 1：表示高于栈顶运算符  0：表示低于等于栈顶
    int operator_order[LEN][LEN] = {{0, 0, 1, 1, 1, 1},
                                    {0, 0, 1, 1, 1, 1},
                                    {0, 0, 0, 0, 1, 0},
                                    {0, 0, 0, 0, 1, 0},
                                    {1, 1, 1, 1, 1, 1},
                                    {0, 0, 0, 0, 1, 0}};
    char op1, op2;                                           // op1：待入栈的运算符  op2： 运算符栈的栈顶运算符
    int order = 0;                                           // 1： 优先级高   0： 低于或等于

    // 如果不是遇到结束标志
    while (*p != '#')
    {
        // 如果遇到操作数 入操作数栈
        if (*p >= '0' && *p <= '9')
        {
            push(pS, atof(p), 1);
        }
        else
        {
            // 如果运算符栈空 直接入栈
            if (-1 == pS->top2)
            {
                push(pS, (float)*p, 2);
            }
            else if (*p == ')')
            {

                op2 =(int)pop(pS, 2);                        //运算符栈  出栈
                while (op2 != '(')                           //一直出栈到（
                {
                    do_oprator(pS, op2);                     //操作数出栈，与相应运算符op2做运算，结果压栈
                    if (-1 != pS->top2)
                    {
                        op2 = pop(pS, 2);                   // 在这里将 '('出栈
                    } else
                    {
                        break;
                    }
                }
            }
            else                                            // 对运算符为 + - * / % 进行处理
            {
                op1 = *p;                                   // 待入栈运算符
                op2 = pS->operation[pS->top2];              // 运算符栈 栈顶运算符

                order = compareOrder(operator, operator_order, op1, op2);  // 比较op1：待入栈元素个栈顶元素优先级大小
//                printf("***order  %d\n", order);
                while (order == 0)
                {
                    op2 = pop(pS, 2);
                    do_oprator(pS, op2);

                    if (-1 != pS->top2)
                    {
                        op2 = pS->operation[pS->top2];
                        order = compareOrder(operator, operator_order, op1, op2);
//                        printf("-----order  %d\n", order);
                    }
                    else
                    {
                        break;
                    }
                }
                push(pS, (float)op1, 2);
            }

        }
        p++;
    }

    // 遇到 # 将运算符栈内元素 出栈
    while (-1 != pS->top2)
    {
        op2 = pop(pS, 2);
        do_oprator(pS, op2);
    }

    traverse(pS, 1);
    traverse(pS, 2);
    printf("运算结果：%.2lf\n", pS->data[pS->top1]);
    return 0;
}

seqStack *createStack()
{
    seqStack *pS = (seqStack *) malloc(sizeof(seqStack));
    if (!pS)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pS->top1 = -1;
    pS->top2 = -1;
    return pS;
}

void push(seqStack *pS, float val, int flag)
{
    if (flag == 1)
    {
        if (MAXSIZE - 1 == pS->top1)
        {
            printf("操作数栈 满！\n");
            return;
        }
        printf("%.2lf进操作数栈！\n", val);
        pS->data[++pS->top1] = val;

    } else
    {
        if (MAXSIZE - 1 == pS->top2)
        {
            printf("运算符栈 满!\n");
            return;
        }
       printf("%c进运算符栈！\n", (char)val);
        pS->operation[++pS->top2] = (char)val;
    }
}

float pop(seqStack *pS, int flag)
{
    if (flag == 1)
    {
        if (-1 == pS->top1)
        {
            printf("操作数栈 空!\n");
            return -1;
        }

        printf("*******: %.2lf 出栈\n", pS->data[pS->top1]);
        return pS->data[pS->top1--];
    }
    else
    {
        if (-1 == pS->top2)
        {
            printf("运算符栈 空!\n");
            return -1;
        }
        printf("*******: %c 出栈\n", pS->operation[pS->top2]);
        return pS->operation[pS->top2--];
    }
}

void traverse(seqStack *pS, int flag)
{
    if (flag == 1)
    {
        int i = pS->top1;
        printf("操作数栈：");
        while (i != -1)
        {
            printf(" %.2lf ", pS->data[i--]);
        }
        printf("\n");
    }
    else
    {
        int j = pS->top2;
        printf("运算符栈：");
        while (j != -1)
        {
            printf(" %c ", pS->operation[j--]);
        }
        printf("\n");
    }
}

int compareOrder(char operator[LEN], int operator_order[LEN][LEN], char op1, char  op2)
{
    // 切记这里的i,j要初始化 要不然 当遇到第一个（时 j = 512
    int i =0 , j = 0;
    // 如果不等于运算符栈顶元素
    while (operator[i] != op2 && i < LEN)
    {
        i++;
    }
    // 如果不等于 待入运算符栈 元素
    while (operator[j] != op1 && j < LEN)
    {
        j++;
    }
    return operator_order[i][j];

}

void do_oprator(seqStack *pS, char op2)
{
    float data1 = pop(pS, 1);
    float data2 = pop(pS, 1);
    switch (op2)
    {
        case '+':
            push(pS, data2 + data1, 1);
            break;
        case '-':
            push(pS, data2 - data1, 1);
            break;
        case '*':
            push(pS, data2 * data1, 1);
            break;
        case '/':
            push(pS, data2 / data1, 1);
            break;
        case '%':      // C语言中取余 只针对整数
            push(pS, (int) data2 % (int) data1, 1);
            break;
        default:
            printf("暂无此功能！\n");
    }
}
