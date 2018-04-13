#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define LEN 6//一维数组长度+ - * / (
#define MAXLEN 100
/*   只能实现一位数*/ 
typedef struct
{
	union
	{
		float data[MAXLEN];//操作数数组
		char oper[MAXLEN];//运算符数组
	}array;

	int top;
}SeqStack;

//1建立空栈
SeqStack * CreateSeqStack()
{
	SeqStack * sq=(SeqStack *) malloc(sizeof(SeqStack));
	sq->top=-1;
	return sq;
}

//2 进栈，标志flag为1：表示x进到操作数数组；2表示进到运算符数组
int Push(SeqStack * sq,float x,int flag)
{
//	printf("x=%d",x);
	if(sq->top==MAXLEN-1)
		return 0;
	else
	{
		sq->top++;
		if(flag==2)//标志为2，说明是个运算符，则进运算符数组
		{
				sq->array.oper[sq->top]=(int)x;
				printf("%c进运算符栈！\n", (char)x);
//			    printf("%c进栈成功!\n",(char)x);
			   

		}
		else//否则标志为1，则进操作数数组
		{	

			sq->array.data[sq->top]=x;
			printf("%.2lf进操作数栈！\n", x);
//			printf("%g进栈成功!\n",x);
		}
		return 1;
	}
}

//4 出栈，flag标志为1表示从操作数数组中出，2表示从运算符数组中出
float Pop(SeqStack * sq,int flag)
{
	float x;
	if(sq->top==-1)
	{
		printf("栈空");
		return 0;
	}
	else
	{
		
		if (flag==1)
		{
			
			x=sq->array.data[sq->top];
		    printf("*******: %.2lf 出栈\n", x);
			
		}
		else
		{
			 x=sq->array.oper[sq->top];
             printf("*******: %c 出栈\n", sq->array.oper[sq->top]);
		 } 
		
		sq->top--;

		return x;
	}
	
}
//从优先级二维数组中查，待进栈的运算符op1的优先级是否高于栈顶运算符op2;高于返回的是1，否则返回的是0
int do_priority(char oper[LEN],int oporder[LEN][LEN],char op1,char op2)
{
	int i=0,j=0;
	int flag=0;

	//寻找两个字符对应的下标数字
	for(i=0;i<LEN && oper[i]!=op1;i++);

	for(j=0;j<LEN && oper[j]!=op2;j++);

	//通过下标数字查二维数字内容
	flag=oporder[j][i];

	return flag;

}

//两个操作数相继出栈，与出栈的运算符op做相应运算，结果进栈
void do_operation(SeqStack *s,char op)
{
	float data1,data2;
	data1=Pop(s,1);
	data2=Pop(s,1);
	printf("\n出栈元素：%g %c %g\n ",data2,op,data1);

	switch(op)
	{
		case '+':Push(s,data2+data1,1);break;
		case '-':Push(s,data2-data1,1);break;
		case '*':Push(s,data2*data1,1);break;
		case '/':Push(s,data2/data1,1);break;
		case '%':Push(s,(int)data2%(int)data1,1);break;
		default:printf("暂无此功能");
	}
}


//混合运算求和
void opration()
{
	SeqStack *s1,*s2;//s1:操作数栈，s2:运算符栈
	char op1,op2;//op1:串中待进栈处理的运算符字符，op2:栈顶的字符
	char oper[LEN]={'+','-','*','/','%','('};//运算符数组,(的优先级高于所有的，其他运算符也都高于(,看到(,直接进栈，
	int  oper_order[LEN][LEN]={{0,0,1,1,1,1},{0,0,1,1,1,1},{0,0,0,0,0,1},{0,0,0,0,0,1},{0,0,0,0,0,1},{1,1,1,1,1,1}};//优先级数组，纵向对比横向，>为1，<=为0；
	char expression[100]="9*9%3+(((5+4*5)+9)-2)#";//待处理的表达式，可实现从键盘输入表达式
	char *p=expression;//指针p指向该字符数组，通过p处理遇到的每一个字符
	char operators;//出栈运算符；
	int order;//优先级结果，1：表示高于栈顶，0：表示不高于

	s1=CreateSeqStack();
	s2=CreateSeqStack();

	while(*p!='#')
	{
		if(*p>='0' && *p<='9' )//是数字字符
		{	
		    printf("%lf\n",(float)(atoi(p)) );
			Push(s1,(float)(atoi(p)),1);	
		}
		else //是运算符，不是操作数，
		{
			if(s2->top==-1)//栈为空,,则直接进栈
			{
				Push(s2,(float)(*p),2);
			}
			else if(*p==')')//是）的处理
			{
				
					op2=(int)Pop(s2,2);//运算符栈  出栈
					while(op2!='(' )//一直出栈到（
					{
						do_operation(s1,op2);//操作数出栈，与相应运算符op2做运算，结果压栈

						if(s2->top!=-1)
							op2=(int)Pop(s2,2);
						else
							break;
					}

			}
			else//是+-*/的处理
			{
				op1=*p;
				op2=(int)(s2->array.oper[s2->top]);

				order=do_priority(oper,oper_order,op1,op2);
		        printf("order  %d\n", order);

				while(order==0)//优先级不高于栈顶
				{
					op2=(int)Pop(s2,2);//运算符栈  出栈

					do_operation(s1,op2);//操作数出栈，与相应运算符op2做运算，结果压栈
				
					if(s2->top!=-1)
					{
						op2=(int )(s2->array.oper[s2->top]);
						order=do_priority(oper,oper_order,op1,op2);
					}
					else
						break;						
				}
								
				Push(s2,(float)(*p),2);//高于栈顶元素,或栈已弹空
				
			}
			
		}
		p++;
	
	}

//	//c处理#
//	while(s2->top!=-1)
//	{
//		op2=(int)Pop(s2,2);//运算符栈  出栈
//		do_operation(s1,op2);//操作数出栈，与相应运算符op2做运算，结果压栈
//	
//	}
//
//
//	printf("运算结果为：%g \n",s1->array.data[s1->top]);

}

void main()
{

	opration();


}
