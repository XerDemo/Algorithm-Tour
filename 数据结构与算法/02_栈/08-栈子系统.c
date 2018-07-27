#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXSIZE 100

typedef struct Node {
    union {
        double num;             // ������
        char opr;               // �����
    } select;
    struct Node *pNext;         // ָ����
} StackNode;

typedef struct {
    StackNode *pTop;           // ջ��ָ��
} LinkStack;

char inExp[MAXSIZE];             // ��׺���ʽ
char postExp[MAXSIZE];           // ��׺���ʽ

LinkStack *createStack();                                           // ������ջ
void push(LinkStack *pS, float val, int flag);                      // ��ջ
float pop(LinkStack *pS, int flag);                                 // ��ջ
int isEmpty(LinkStack *pS);                                         // ջ��
void conversion(LinkStack *pS, int num, int flag);                  //ʮ����ת������
char readOprTop(LinkStack *pS);                                     // ��ȡջ��Ԫ��
void infixToPostfix(LinkStack * pS);                                // ��׺���ʽ ת ��׺���ʽ
void postfixResult(LinkStack * pS);                                 // ��׺���ʽ��ֵ
void clearStack(LinkStack * pS);									// ���ջ
 


int main(void)
{
    LinkStack *pS = createStack();
    int choice;
    int num; 
    
    while (1)
    {
    	printf("\n\t		    	ջ��ϵͳ                       ");
		printf("\n\t\t**********************************************");
		printf("\n\t\t*              1----�� ջ                    *");
		printf("\n\t\t*              2----�� ջ                    *");
		printf("\n\t\t*              3----�� ʾ                    *");
		printf("\n\t\t*              4----����ת��                 *");
		printf("\n\t\t*              5----�沨��ʽ                 *");
		printf("\n\t\t*              6----�沨��ʽ��ֵ             *");
		printf("\n\t\t*              0----�� ��                    *");
		printf("\n\t\t**********************************************");   
		printf("\n\t\t��ѡ��˵���(0-6):");
		scanf("%d", &choice);
	
		switch(choice)
		{
			case 1:
				while (1)
				{
					printf("\t\t����һ������(-1����):");
					scanf("%d", &num);
					if (-1 != num)
					{
						push(pS, num, 1);	
					} 
					else
					{
						break;
					}
				}
		    	break;
			case 2:
				printf("\t\t��ջԪ��Ϊ��%d\n", (int)pop(pS,1));
				break;
			case 3:
			    printf("\n\t\tջ��Ԫ�أ�");
				while (!isEmpty(pS)) 
				{
					printf("%d ", (int)pop(pS,1));
				}
				printf("\n");
				break;
			case 4:
				printf("\n\t\t������һ��ʮ������������");
				scanf("%d", &num);
				conversion(pS, num, 1);
				break;
			case 5:
				fflush(stdin);
				clearStack(pS);
				infixToPostfix(pS);
				break;
			case 6:
				postfixResult(pS);
				break; 
			case 0:
				exit(0);
            default:
            	printf("\n\t\t���޴�ѡ����������룡\n");
            	break;
		}  
	}
    return 0;
}

// ���ջ 
void clearStack(LinkStack * pS)
{
	while (!isEmpty(pS))
	{
		pop(pS,1);	
	}	
}

// ��ȡջ��Ԫ��
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

// ��׺���ʽ ת ��׺���ʽ
void infixToPostfix(LinkStack * pS)
{

    printf("��������׺���ʽ:\n");
    gets(inExp);

    int inLen = strlen(inExp);       // ��׺���ʽ����
    inExp[inLen] = '\0';             // �ֶ����Ͻ�����־

    int i, t = 0;                    // i:inExp���±�   t:postExp���±�
    char ch = inExp[i++];
    // �����׺���ʽһ��ʼ�����ľ��� - + �� ��-2 ���0-2
    if (ch == '-' || ch == '+')
    {
        postExp[t++] = '0';
        postExp[t++] = ',';
    }

    // ֻҪû�������ַ����������־'\0'
    while (ch != '\0')
    {
        switch (ch)
        {
            case '(':               // '(' Ϊ��ջǰ '('���ȼ���� ֱ����ջ
                push(pS, ch, 2);
                break;
            case ')':               // ����')' ��ջ ֱ�� ���� ')' ���'('Ҳ����
                while (readOprTop(pS) != '(')
                {
                    postExp[t++] = pop(pS, 2);
                    postExp[t++] = ',';
                }
                pop(pS, 2);            // ���� '('
                break;
            case '+':
            case '-':               // ���� + - ֻ�е�ջ�� ����ջ��Ԫ��Ϊ '(' �Ž�ջ
                while (!isEmpty(pS) && readOprTop(pS) != '(')
                {
                    postExp[t++] = pop(pS, 2);
                    postExp[t++] = ',';
                }
                push(pS, ch, 2);
                break;
            case '%':
            case '*':
            case '/':               // & * / �������ȼ������͵ĲŽ�ջ
                while (readOprTop(pS) == '%' || readOprTop(pS) == '*' || readOprTop(pS) == '/')
                {
                    postExp[t++] = pop(pS, 2);
                    postExp[t++] = ',';
                }
                push(pS, ch, 2);
                break;
            default:                // ��Ϊ���� ���� С����ʱ
                while (ch >= '0' && ch <= '9' || ch == '.')
                {
                    postExp[t++] = ch;
                    ch = inExp[i++];
                }
                i--;    // ����
                postExp[t++] = ',';
        }
        ch = inExp[i++];  // ������
    }

    // ֻҪջ��Ϊ��
    while (!isEmpty(pS))
    {
        postExp[t++] = pop(pS, 2);
        if (!isEmpty(pS))
        {
            postExp[t++] = ',';
        }
    }
    postExp[t] = '\0';          // '\0'��ΪpostExp�Ľ�����־

    printf("��׺���ʽ��");
    puts(inExp);
    printf("��׺���ʽ:");
    puts(postExp);
}


// ��׺���ʽ��ֵ
void postfixResult(LinkStack * pS)
{
    int i = 0;
    char ch = postExp[i++];
    char temp[MAXSIZE];     // ��ʱ���ʶ��ĸ����� ͨ��atof����double
    float op1, op2;         // ������1 ������2
    while (ch != '\0')
    {
        int t = 0;          // ÿ��ʶ�𸡵��� temp���±긴ԭ
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
                    printf("������ĸ����Ϊ0��\n");
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
                temp[t] = '\0';         // ��ؼ��� ������־ Ҫ��Ȼ atof�����
                i--;    // ����
                push(pS, atof(temp), 1);
        }
        ch = postExp[i++];
    }
    printf("��׺���ʽ�����%lf\n", pop(pS, 1));
}

// ��ʮ���� ת�� ������
void conversion(LinkStack *pS, int num, int flag)
{
    int t = num;
    pS->pTop = NULL;            //�Ƚ�ջ���
    while (num != 0)
    {
        int remainder = num % 2;
        push(pS, remainder, 1);
        num /= 2;
    }

    printf("\t\t%d�Ķ�����:", t);
    while (!isEmpty(pS))
    {
        printf("%d", (int)pop(pS,1));
    }
    printf("\n");
}

// ��ջ
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

// ��ջ
void push(LinkStack *pS, float val, int flag)
{
    StackNode *pNew = (StackNode *) malloc(sizeof(StackNode));     // ʡ���ж�pNewΪNULL
    if (flag == 1)
    {
        pNew->select.num = val;
        // printf("%.4lf��ջ\n", val);
    } else
    {
        pNew->select.opr = (char)val;
        // printf("%c��ջ\n", (char)val);
    }
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

// ��ջ
float pop(LinkStack *pS, int flag)
{
    float p;
    if (isEmpty(pS))
    {
        printf("ջ��.\n");
    } else
    {
        StackNode *pTemp = pS->pTop;
        if (flag == 1)
        {
            p = pTemp->select.num;
            // printf("%.4lf��---->ջ\n", p);
        } else
        {
            p = pTemp->select.opr;
            // printf("%c��ջ\n", (char)p);
        }
        pS->pTop = pTemp->pNext;
        return p;
    }
}


