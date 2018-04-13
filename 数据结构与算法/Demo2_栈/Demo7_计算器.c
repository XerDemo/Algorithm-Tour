#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define LEN 6

/**
 *  �������ļ�ʵ�� + - * / % ����
 *  ֻ��ʵ��һλ�� 
 */

typedef struct stack
{
    float data[MAXSIZE];                                          // ����������
    char operation[MAXSIZE];                                      // ���������
    int top1;                                                     // ������ջ��ָ��
    int top2;                                                     // �����ջ��ָ��
} seqStack;

seqStack *createStack();                                          // ��ʼ��
void push(seqStack *ps, float val, int flag);                     // ��ջ  flag == 1 �������ջ   ��֮ �������ջ
float pop(seqStack *pS, int flag);                                // ��ջ  flag == 1 ��������ջ   ��֮ �������ջ
void traverse(seqStack *pS, int flag);                            // ����
int compareOrder(char operator[LEN], int operator_order[LEN][LEN], char op1, char  op2); // ����op2 ��op1�����ȼ���С
void do_oprator(seqStack *pS, char op2);                                                 // ���������op2���ڲ�����ȡ������������

int main(void)
{
//    "9*9%3+(((5+4*5)+9)-2)#"
//    "(4*3)*1+2+(4*3)#"
    seqStack * pS =createStack();
    char input[100] ="(4*3)*1+2+(4*3)#" ;              // ����ı��ʽ
    // gets(input);                                          // '#' ������־ �û���������
    char *p = input;                                         // ָ��pָ����ַ����� ͨ��p���ƶ�������  �������ַ�
    // ��������� δ��ջ֮ǰ '('�����ȼ���ߣ���ջ֮��'('�����ȼ���� ,����')'ջ��Ԫ�ص�����'('����Ϊֹ�� ����ջ����������ȼ�����ջ��������Ž�ջ��С�ڵ���ջ��Ԫ�س�ջ �������ջһ�� ��������ջ����
    char operator[LEN] = {'+', '-', '*', '/', '(', '%'};     // ����Ƚϴ���ջ����� * ��ջ��Ԫ���+,��operator��'+':0   ��operator��'*':2  Ȼ��operator_order��[0][2]Ϊ1��op1���ȼ���
    // ���ȼ����� 1����ʾ����ջ�������  0����ʾ���ڵ���ջ��
    int operator_order[LEN][LEN] = {{0, 0, 1, 1, 1, 1},
                                    {0, 0, 1, 1, 1, 1},
                                    {0, 0, 0, 0, 1, 0},
                                    {0, 0, 0, 0, 1, 0},
                                    {1, 1, 1, 1, 1, 1},
                                    {0, 0, 0, 0, 1, 0}};
    char op1, op2;                                           // op1������ջ�������  op2�� �����ջ��ջ�������
    int order = 0;                                           // 1�� ���ȼ���   0�� ���ڻ����

    // �����������������־
    while (*p != '#')
    {
        // ������������� �������ջ
        if (*p >= '0' && *p <= '9')
        {
            push(pS, atof(p), 1);
        }
        else
        {
            // ��������ջ�� ֱ����ջ
            if (-1 == pS->top2)
            {
                push(pS, (float)*p, 2);
            }
            else if (*p == ')')
            {

                op2 =(int)pop(pS, 2);                        //�����ջ  ��ջ
                while (op2 != '(')                           //һֱ��ջ����
                {
                    do_oprator(pS, op2);                     //��������ջ������Ӧ�����op2�����㣬���ѹջ
                    if (-1 != pS->top2)
                    {
                        op2 = pop(pS, 2);                   // �����ｫ '('��ջ
                    } else
                    {
                        break;
                    }
                }
            }
            else                                            // �������Ϊ + - * / % ���д���
            {
                op1 = *p;                                   // ����ջ�����
                op2 = pS->operation[pS->top2];              // �����ջ ջ�������

                order = compareOrder(operator, operator_order, op1, op2);  // �Ƚ�op1������ջԪ�ظ�ջ��Ԫ�����ȼ���С
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

    // ���� # �������ջ��Ԫ�� ��ջ
    while (-1 != pS->top2)
    {
        op2 = pop(pS, 2);
        do_oprator(pS, op2);
    }

    traverse(pS, 1);
    traverse(pS, 2);
    printf("��������%.2lf\n", pS->data[pS->top1]);
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
            printf("������ջ ����\n");
            return;
        }
        printf("%.2lf��������ջ��\n", val);
        pS->data[++pS->top1] = val;

    } else
    {
        if (MAXSIZE - 1 == pS->top2)
        {
            printf("�����ջ ��!\n");
            return;
        }
       printf("%c�������ջ��\n", (char)val);
        pS->operation[++pS->top2] = (char)val;
    }
}

float pop(seqStack *pS, int flag)
{
    if (flag == 1)
    {
        if (-1 == pS->top1)
        {
            printf("������ջ ��!\n");
            return -1;
        }

        printf("*******: %.2lf ��ջ\n", pS->data[pS->top1]);
        return pS->data[pS->top1--];
    }
    else
    {
        if (-1 == pS->top2)
        {
            printf("�����ջ ��!\n");
            return -1;
        }
        printf("*******: %c ��ջ\n", pS->operation[pS->top2]);
        return pS->operation[pS->top2--];
    }
}

void traverse(seqStack *pS, int flag)
{
    if (flag == 1)
    {
        int i = pS->top1;
        printf("������ջ��");
        while (i != -1)
        {
            printf(" %.2lf ", pS->data[i--]);
        }
        printf("\n");
    }
    else
    {
        int j = pS->top2;
        printf("�����ջ��");
        while (j != -1)
        {
            printf(" %c ", pS->operation[j--]);
        }
        printf("\n");
    }
}

int compareOrder(char operator[LEN], int operator_order[LEN][LEN], char op1, char  op2)
{
    // �м������i,jҪ��ʼ�� Ҫ��Ȼ ��������һ����ʱ j = 512
    int i =0 , j = 0;
    // ��������������ջ��Ԫ��
    while (operator[i] != op2 && i < LEN)
    {
        i++;
    }
    // ��������� ���������ջ Ԫ��
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
        case '%':      // C������ȡ�� ֻ�������
            push(pS, (int) data2 % (int) data1, 1);
            break;
        default:
            printf("���޴˹��ܣ�\n");
    }
}
