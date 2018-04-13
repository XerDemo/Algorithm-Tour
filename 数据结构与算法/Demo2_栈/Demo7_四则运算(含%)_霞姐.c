#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define LEN 6//һά���鳤��+ - * / (
#define MAXLEN 100
/*   ֻ��ʵ��һλ��*/ 
typedef struct
{
	union
	{
		float data[MAXLEN];//����������
		char oper[MAXLEN];//���������
	}array;

	int top;
}SeqStack;

//1������ջ
SeqStack * CreateSeqStack()
{
	SeqStack * sq=(SeqStack *) malloc(sizeof(SeqStack));
	sq->top=-1;
	return sq;
}

//2 ��ջ����־flagΪ1����ʾx�������������飻2��ʾ�������������
int Push(SeqStack * sq,float x,int flag)
{
//	printf("x=%d",x);
	if(sq->top==MAXLEN-1)
		return 0;
	else
	{
		sq->top++;
		if(flag==2)//��־Ϊ2��˵���Ǹ��������������������
		{
				sq->array.oper[sq->top]=(int)x;
				printf("%c�������ջ��\n", (char)x);
//			    printf("%c��ջ�ɹ�!\n",(char)x);
			   

		}
		else//�����־Ϊ1���������������
		{	

			sq->array.data[sq->top]=x;
			printf("%.2lf��������ջ��\n", x);
//			printf("%g��ջ�ɹ�!\n",x);
		}
		return 1;
	}
}

//4 ��ջ��flag��־Ϊ1��ʾ�Ӳ����������г���2��ʾ������������г�
float Pop(SeqStack * sq,int flag)
{
	float x;
	if(sq->top==-1)
	{
		printf("ջ��");
		return 0;
	}
	else
	{
		
		if (flag==1)
		{
			
			x=sq->array.data[sq->top];
		    printf("*******: %.2lf ��ջ\n", x);
			
		}
		else
		{
			 x=sq->array.oper[sq->top];
             printf("*******: %c ��ջ\n", sq->array.oper[sq->top]);
		 } 
		
		sq->top--;

		return x;
	}
	
}
//�����ȼ���ά�����в飬����ջ�������op1�����ȼ��Ƿ����ջ�������op2;���ڷ��ص���1�����򷵻ص���0
int do_priority(char oper[LEN],int oporder[LEN][LEN],char op1,char op2)
{
	int i=0,j=0;
	int flag=0;

	//Ѱ�������ַ���Ӧ���±�����
	for(i=0;i<LEN && oper[i]!=op1;i++);

	for(j=0;j<LEN && oper[j]!=op2;j++);

	//ͨ���±����ֲ��ά��������
	flag=oporder[j][i];

	return flag;

}

//������������̳�ջ�����ջ�������op����Ӧ���㣬�����ջ
void do_operation(SeqStack *s,char op)
{
	float data1,data2;
	data1=Pop(s,1);
	data2=Pop(s,1);
	printf("\n��ջԪ�أ�%g %c %g\n ",data2,op,data1);

	switch(op)
	{
		case '+':Push(s,data2+data1,1);break;
		case '-':Push(s,data2-data1,1);break;
		case '*':Push(s,data2*data1,1);break;
		case '/':Push(s,data2/data1,1);break;
		case '%':Push(s,(int)data2%(int)data1,1);break;
		default:printf("���޴˹���");
	}
}


//����������
void opration()
{
	SeqStack *s1,*s2;//s1:������ջ��s2:�����ջ
	char op1,op2;//op1:���д���ջ�����������ַ���op2:ջ�����ַ�
	char oper[LEN]={'+','-','*','/','%','('};//���������,(�����ȼ��������еģ����������Ҳ������(,����(,ֱ�ӽ�ջ��
	int  oper_order[LEN][LEN]={{0,0,1,1,1,1},{0,0,1,1,1,1},{0,0,0,0,0,1},{0,0,0,0,0,1},{0,0,0,0,0,1},{1,1,1,1,1,1}};//���ȼ����飬����ԱȺ���>Ϊ1��<=Ϊ0��
	char expression[100]="9*9%3+(((5+4*5)+9)-2)#";//������ı��ʽ����ʵ�ִӼ���������ʽ
	char *p=expression;//ָ��pָ����ַ����飬ͨ��p����������ÿһ���ַ�
	char operators;//��ջ�������
	int order;//���ȼ������1����ʾ����ջ����0����ʾ������

	s1=CreateSeqStack();
	s2=CreateSeqStack();

	while(*p!='#')
	{
		if(*p>='0' && *p<='9' )//�������ַ�
		{	
		    printf("%lf\n",(float)(atoi(p)) );
			Push(s1,(float)(atoi(p)),1);	
		}
		else //������������ǲ�������
		{
			if(s2->top==-1)//ջΪ��,,��ֱ�ӽ�ջ
			{
				Push(s2,(float)(*p),2);
			}
			else if(*p==')')//�ǣ��Ĵ���
			{
				
					op2=(int)Pop(s2,2);//�����ջ  ��ջ
					while(op2!='(' )//һֱ��ջ����
					{
						do_operation(s1,op2);//��������ջ������Ӧ�����op2�����㣬���ѹջ

						if(s2->top!=-1)
							op2=(int)Pop(s2,2);
						else
							break;
					}

			}
			else//��+-*/�Ĵ���
			{
				op1=*p;
				op2=(int)(s2->array.oper[s2->top]);

				order=do_priority(oper,oper_order,op1,op2);
		        printf("order  %d\n", order);

				while(order==0)//���ȼ�������ջ��
				{
					op2=(int)Pop(s2,2);//�����ջ  ��ջ

					do_operation(s1,op2);//��������ջ������Ӧ�����op2�����㣬���ѹջ
				
					if(s2->top!=-1)
					{
						op2=(int )(s2->array.oper[s2->top]);
						order=do_priority(oper,oper_order,op1,op2);
					}
					else
						break;						
				}
								
				Push(s2,(float)(*p),2);//����ջ��Ԫ��,��ջ�ѵ���
				
			}
			
		}
		p++;
	
	}

//	//c����#
//	while(s2->top!=-1)
//	{
//		op2=(int)Pop(s2,2);//�����ջ  ��ջ
//		do_operation(s1,op2);//��������ջ������Ӧ�����op2�����㣬���ѹջ
//	
//	}
//
//
//	printf("������Ϊ��%g \n",s1->array.data[s1->top]);

}

void main()
{

	opration();


}
