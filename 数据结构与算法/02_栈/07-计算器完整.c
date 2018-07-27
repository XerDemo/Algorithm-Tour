#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct Node {
    union {
        double num;             // 运算数
        char opr;               // 运算符
    } select;
    struct Node *pNext;         // 指针域
} StackNode;

typedef struct {
    StackNode *pTop;           // 栈顶指针
} LinkStack;

char inExp[MAXSIZE];             // 中缀表达式
char postExp[MAXSIZE];           // 后缀表达式

LinkStack *createStack();                                           // 创建链栈
void push(LinkStack *pS, float val, int flag);                      // 进栈
float pop(LinkStack *pS, int flag);                                 // 出栈
int isEmpty(LinkStack *pS);                                         // 栈空
char readOprTop(LinkStack *pS);                                     // 读取栈顶元素
void infixToPostfix(LinkStack * pS);                                // 中缀表达式 转 后缀表达式
void postfixResult(LinkStack * pS);                                 // 后缀表达式求值


int main(void)
{
    LinkStack *pS = createStack();
    infixToPostfix(pS);
    postfixResult(pS);
    return 0;
}

// 读取栈顶元素
char readOprTop(LinkStack *pS)
{
    if (isEmpty(pS))
    {
        return (char) -1;
    } else
    {
        return pS->pTop->select.opr;
    }
}

// 中缀表达式 转 后缀表达式
void infixToPostfix(LinkStack * pS)
{

    printf("请输入中缀表达式:\n");
    gets(inExp);

    int inLen = strlen(inExp);       // 中缀表达式长度
    inExp[inLen] = '\0';             // 手动加上结束标志

    int i, t = 0;                    // i:inExp的下标   t:postExp的下标
    char ch = inExp[i++];
    // 如果中缀表达式一开始遇到的就是 - + 号 如-2 变成0-2
    if (ch == '-' || ch == '+')
    {
        postExp[t++] = '0';
        postExp[t++] = ',';
    }

    // 只要没有遇到字符数组结束标志'\0'
    while (ch != '\0')
    {
        switch (ch)
        {
            case '(':               // '(' 为入栈前 '('优先级最大 直接入栈
                push(pS, ch, 2);
                break;
            case ')':               // 遇到')' 弹栈 直到 弹到 ')' 最后将'('也弹出
                while (readOprTop(pS) != '(')
                {
                    postExp[t++] = pop(pS, 2);
                    postExp[t++] = ',';
                }
                pop(pS, 2);            // 弹出 '('
                break;
            case '+':
            case '-':               // 遇到 + - 只有当栈空 或者栈顶元素为 '(' 才进栈
                while (!isEmpty(pS) && readOprTop(pS) != '(')
                {
                    postExp[t++] = pop(pS, 2);
                    postExp[t++] = ',';
                }
                push(pS, ch, 2);
                break;
            case '%':
            case '*':
            case '/':               // & * / 遇到优先级比它低的才进栈
                while (readOprTop(pS) == '%' || readOprTop(pS) == '*' || readOprTop(pS) == '/')
                {
                    postExp[t++] = pop(pS, 2);
                    postExp[t++] = ',';
                }
                push(pS, ch, 2);
                break;
            default:                // 当为数字 或者 小数点时
                while (ch >= '0' && ch <= '9' || ch == '.')
                {
                    postExp[t++] = ch;
                    ch = inExp[i++];
                }
                i--;    // 回退
                postExp[t++] = ',';
        }
        ch = inExp[i++];  // 往后移
    }

    // 只要栈不为空
    while (!isEmpty(pS))
    {
        postExp[t++] = pop(pS, 2);
        if (!isEmpty(pS))
        {
            postExp[t++] = ',';
        }
    }
    postExp[t] = '\0';          // '\0'作为postExp的结束标志

    printf("中缀表达式：");
    puts(inExp);
    printf("后缀表达式:");
    puts(postExp);
}


// 后缀表达式求值
void postfixResult(LinkStack * pS)
{
    int i = 0;
    char ch = postExp[i++];
    char temp[MAXSIZE];     // 临时存放识别的浮点数 通过atof换成double
    float op1, op2;         // 操作数1 操作数2
    while (ch != '\0')
    {
        int t = 0;          // 每次识别浮点数 temp的下标复原
        switch (ch)
        {
            case ',':
                break;
            case '+':
                op1 = pop(pS, 1);
                op2 = pop(pS, 1);
                push(pS, op2 + op1, 1);
                break;

            case '-':
                op1 = pop(pS, 1);
                op2 = pop(pS, 1);
                push(pS, op2 - op1, 1);
                break;
            case '*':
                op1 = pop(pS, 1);
                op2 = pop(pS, 1);
                push(pS, op2 * op1, 1);
                break;
            case '/':
                op1 = pop(pS, 1);
                op2 = pop(pS, 1);
                if (op1 == 0)
                {
                    printf("除法分母不能为0！\n");
                } else{
                    push(pS, op2 / op1, 1);
                }
                break;
            case '%':
                op1 = pop(pS, 1);
                op2 = pop(pS, 1);
                push(pS, (int)op2 % (int)op1, 1);
                break;
            default:
                while (ch >= '0' && ch <= '9' || ch == '.')
                {
                    temp[t++] = ch;
                    ch = postExp[i++];
                }
                temp[t] = '\0';         // 务必加上 结束标志 要不然 atof会出错
                i--;    // 回退
                push(pS, atof(temp), 1);
        }
        ch = postExp[i++];
    }
    printf("后缀表达式结果：%lf\n", pop(pS, 1));
}

// 建栈
LinkStack *createStack()
{
    LinkStack *pS = (LinkStack *) malloc(sizeof(LinkStack));
    pS->pTop = NULL;
    return pS;
}

int isEmpty(LinkStack *pS)
{
    return pS->pTop == NULL;
}

// 进栈
void push(LinkStack *pS, float val, int flag)
{
    StackNode *pNew = (StackNode *) malloc(sizeof(StackNode));     // 省略判断pNew为NULL
    if (flag == 1)
    {
        pNew->select.num = val;
        // printf("%.4lf进栈\n", val);
    } else
    {
        pNew->select.opr = (char)val;
        // printf("%c进栈\n", (char)val);
    }
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

// 出栈
float pop(LinkStack *pS, int flag)
{
    float p;
    if (isEmpty(pS))
    {
        printf("栈空.\n");
    } else
    {
        StackNode *pTemp = pS->pTop;
        if (flag == 1)
        {
            p = pTemp->select.num;
            // printf("%.4lf出---->栈\n", p);
        } else
        {
            p = pTemp->select.opr;
            // printf("%c出栈\n", (char)p);
        }
        pS->pTop = pTemp->pNext;
        return p;
    }
}

