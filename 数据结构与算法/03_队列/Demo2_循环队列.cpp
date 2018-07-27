#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

typedef struct queue{
	int data[MAXSIZE];
	int front;								//  队头指针  始终指向对头元素的前一个位置
	int rear;								//  队尾指针  始终指向队尾最后一个元素
}cycleQueue;
/*
     “先进先出”   画个图 就 都懂了 
	顺序队列与循环队列的区别：(使用循环队列)
		循环队列：1.判断空 pQ->front == pQ->rear (0)
			  2.判断满 (pQ->rear + 1) % 数组长度 == pQ->front
			  3.front   rear  都是从 0开始
			  4.如何区分队列是满还是空      
		     	方法1：另外增设一个变量 充当计数器 n 当 n == 0 队列空  当 n == MAXSIZE(数组长度) 队列满   
			 	方法2：少用一个空间元素  即队列中最多只能存在 数组长度-1 个元素   
			  5. 判断队列长度   
			               (pQ->rear - pQ->front + MAXSIZE ) % MAXSIZE
			 	
		顺序队列：1.判断空   pQ->front == pQ->rear
			  2.判断满   MAXSIZE - 1 == pQ->rear
			  3.出队的元素的位置（出队元素并不会被删除只是front移到） 会被一直占用 ， 而循环队列解决了这个问题
			  4.顺序队列 front rear 从-1开始             循环队列： front  rear 从0开始 
			  5. 判断队列长度   pQ->rear - pQ->front 
*/ 
void init_queue(cycleQueue * pQ);	 									// 函数声明的方式 
cycleQueue * create_queue();											// malloc "挖坑"的方式 									
bool full_queue(cycleQueue * pQ);										// 判断循环队列是否满										
bool empty_queue(cycleQueue * pQ);										// 判断循环队列是否满
bool out_queue(cycleQueue *pQ, int * pVal);                             // 出队 
bool in_queue(cycleQueue * pQ, int val);								// 入队 
int length_queue(cycleQueue * pQ);										// 队列长度 
void traverse_queue(cycleQueue * pQ);									// 遍历 

int main (void)
{
	// 函数声明的方式 
	cycleQueue Q;
	init_queue(&Q);
	
	// malloc "挖坑"的方式 
	cycleQueue * pQ = create_queue();
	int val;
	
	in_queue(pQ, 1); 
	in_queue(pQ, 2);
	if (out_queue(pQ, &val)) 
	{
		printf("out_queue is : %d\n", val);
	}
	
	in_queue(pQ, 3); 
	in_queue(pQ, 4);
	
	printf("len = %d \n", length_queue(pQ));
	
	traverse_queue(pQ); 
	
	return 0;
}

void init_queue(cycleQueue * pQ)
{
	pQ->front = pQ->rear = 0; 
} 

cycleQueue * create_queue()
{
	cycleQueue * pQ = (cycleQueue * ) malloc (sizeof(cycleQueue));
	if (!pQ)
	{
		printf("malloc is failed!\n");
		exit(-1);
	}
	pQ->rear = 0;
	pQ->front = 0; 
}

bool full_queue(cycleQueue * pQ)
{
	return (pQ->rear+1)%MAXSIZE == pQ->front; 
}

bool empty_queue(cycleQueue * pQ)
{
	return pQ->front == pQ->rear;
}

bool in_queue(cycleQueue * pQ, int val)
{
	if (full_queue(pQ))
	{
		printf("cycleQueue is full! in_queue is failed!\n");
		return false;
	}
	pQ->rear = (pQ->rear + 1) % MAXSIZE;
	pQ->data[pQ->rear] = val;
	return true;
}

bool out_queue(cycleQueue *pQ, int * pVal)
{
	if (empty_queue(pQ))
	{
		printf("cycleQueue is empty! out_queue is failed!\n");
		return false;
	}
	pQ->front = (pQ->front + 1) % MAXSIZE;
	*pVal = pQ->data[pQ->front];	
	return true; 
}

int length_queue(cycleQueue * pQ)
{
	return (pQ->rear - pQ->front + MAXSIZE ) % MAXSIZE;
} 
void traverse_queue(cycleQueue * pQ)
{
	if (empty_queue(pQ))
	{
		printf("cycleQueue is empty! traverse_queue is exit!");
		return;
	}
	int i = pQ->front;
	printf("cycleQueue is : ");
	while (i != pQ->rear)
	{
		i = (i+1) % MAXSIZE ;
		printf(" %d  ", pQ->data[i]);
	}
	printf("\n");
}
