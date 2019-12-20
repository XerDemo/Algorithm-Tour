////_DataStructure_C_Impl:
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef char DataType;
//
//typedef struct QNode{	//只有队尾指针的链式循环队列类型定义
//    DataType data;
//    struct QNode *next;
//}LQNode,*LinkQueue;
//
////将带头结点的链式循环队列初始化为空队列，需要把头结点的指针指向头结点
//void InitQueue(LinkQueue *rear){
//    if((*rear=(LQNode*)malloc(sizeof(LQNode)))==NULL)
//        exit(-1);		//如果申请结点空间失败退出
//    else
//        (*rear)->next=*rear;	//队尾指针指向头结点
//}
////判断链式队列是否为空，队列为空返回1，否则返回0
//int QueueEmpty(LinkQueue rear){
//    if(rear->next==rear)
//        return 1;
//    else
//        return 0;
//}
////将元素e插入到链式队列中，插入成功返回1
//int EnterQueue(LinkQueue *rear,DataType e){
//    printf("rear: %d \n", (*rear)->data);
//    LQNode *s;
//    s=(LQNode *)malloc(sizeof(LQNode));	//为将要入队的元素申请一个结点的空间
//    if(!s)
//        exit(-1);
//    s->data=e;		//将元素值赋值给结点的数据域
//    s->next=(*rear)->next;		//将新结点插入链式队列
//    (*rear)->next=s;
//    *rear=s;	//修改队尾指针
//    return 1;
//}
////删除链式队列中的队头元素，并将该元素赋值给e，删除成功返回1，否则返回0
//int DeleteQueue(LinkQueue *rear,DataType *e){
//    LQNode *f,*p;
//    if(*rear==(*rear)->next)		//在删除队头元素即出队列之前，判断链式队列是否为空
//        return 0;
//    else{
//        f=(*rear)->next;	//使指针f指向头结点
//        p=f->next;		//使指针p指向要删除的结点
//        if(p==*rear){		//处理队列中只有一个结点的情况
//            *rear=(*rear)->next;		//使指针rear指向头结点
//            (*rear)->next=*rear;
//        }else{
//            f->next=p->next;	//使头结点指向要出队列的下一个结点
//        }
//        *e=p->data;	//把队头元素值赋值给e
//        free(p);	//释放指针p指向的结点
//        return 1;
//    }
//}
//
//int main(){
//	LinkQueue LQueue1,LQueue2;		/*定义链式循环队列*/
//	InitQueue(&LQueue1);				/*初始化链式循环队列1*/
//    EnterQueue(&LQueue1, 1);
//    EnterQueue(&LQueue1, 2);
//    EnterQueue(&LQueue1, 3);
//    EnterQueue(&LQueue1, 4);
//    DataType val;
//    DeleteQueue(&LQueue1, &val);
//    printf(" %d ", val);
////	InitQueue(&LQueue2);				/*初始化链式循环队列2*/
////	InitStack(&LStack1);				/*初始化链式堆栈1*/
////	InitStack(&LStack2);				/*初始化链式堆栈2*/
////	for(i=0;i<strlen(str1);i++)
////	{
////		EnterQueue(&LQueue1,str1[i]);	/*依次把字符序列1入队*/
////		EnterQueue(&LQueue2,str2[i]);	/*依次把字符序列2入队*/
////		PushStack(LStack1,str1[i]);		/*依次把字符序列1进栈*/
////		PushStack(LStack2,str2[i]);		/*依次把字符序列2进栈*/
////
////	}
////	printf("字符序列1：\n");
////	printf("出队序列  出栈序列\n");
////	while(!StackEmpty(LStack1))			/*判断堆栈1是否为空*/
////	{
////		DeleteQueue(&LQueue1,&q1);		/*字符序列依次出队，并把出队元素赋值给q*/
////		PopStack(LStack1,&s1);			/*字符序列出栈，并把出栈元素赋值给s*/
////		printf("%5c",q1);				/*输出字符序列1*/
////		printf("%10c\n",s1);
////		if(q1!=s1)						/*判断字符序列1是否是回文*/
////		{
////			printf("字符序列1不是回文！");
////			return 0;
////		}
////	}
////	printf("字符序列1是回文！\n");
////	printf("字符序列2：\n");
////	printf("出队序列  出栈序列\n");
////	while(!StackEmpty(LStack2))			/*判断堆栈2是否为空*/
////	{
////		DeleteQueue(&LQueue2,&q2);		/*字符序列依次出队，并把出队元素赋值给q*/
////		PopStack(LStack2,&s2);			/*字符序列出栈，并把出栈元素赋值给s*/
////		printf("%5c",q2);				/*输出字符序列2*/
////		printf("%10c\n",s2);
////		if(q2!=s2)						/*判断字符序列2是否是回文*/
////		{
////			printf("字符序列2不是回文！\n");
////			return 0;
////		}
////	}
////	printf("字符序列2是回文！\n");
////	system("pause");
//    return 0;
//}
