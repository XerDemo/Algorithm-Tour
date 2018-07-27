
#include <stdio.h>
#include <stdlib.h>
/*************************链式队列——链表实现*******************************************/
typedef struct Node{
	int data;
	struct Node * pNext;
}NODE, *PNODE;

typedef struct Queue{
    PNODE front;                // 队头指针 
	PNODE rear;                 // 队尾指针 
	int count;	                // 计数器 
}QUEUE, *PQUEUE;

void init_queue(PQUEUE pQ);                                   // 初始化 队列 
bool en_queue(PQUEUE pQ, int val);                            // 入队 
bool is_empty(PQUEUE pQ);                                     // 判断队列是否空 
void traverse_queue(PQUEUE pQ);                               // 遍历 
bool delete_queue(PQUEUE pQ, int * pVal);                     // 出队             
int length_queue(PQUEUE pQ);                                  // 队列长度 
void clear_queue(PQUEUE pQ);                                  // 清空队列 
void destroy_queue(PQUEUE pQ);                                // 销毁队列 

int main(void)
{
	QUEUE Q;
	int val;
	init_queue(&Q);
	printf("Q.front = %p   Q.rear = %p\n", Q.front, Q.rear);
	en_queue(&Q,1);
	en_queue(&Q,2);
	en_queue(&Q,3);
	if (delete_queue(&Q, &val))
	{
		printf("出队元素：%d\n", val);
	}
	en_queue(&Q,4);
	printf("队列长度：%d\n", length_queue(&Q));
	traverse_queue(&Q);
	
	printf("清空队列！\n");
	clear_queue(&Q);
	printf("队列长度：%d\n", length_queue(&Q));
	traverse_queue(&Q);
	
	en_queue(&Q,10);
	en_queue(&Q,11);
	printf("队列长度：%d\n", length_queue(&Q));
	traverse_queue(&Q);
	
	printf("销毁队列！\n");
	destroy_queue(&Q);
	printf("Q.front = %p   Q.rear = %p\n", Q.front, Q.rear);
	return 0;	
} 

// 初始化    1.一开始没有元素时 需要有一个头节点方便操作 此时front和rear都指向头结点  rear代表最后一个节点 rear->pNext == NULL  count ==0 
void init_queue(PQUEUE pQ)
{
	pQ->front = (PNODE) malloc (sizeof(NODE));
	if (!pQ->front)
	{
		printf("动态内存分配失败!\n");
		exit(-1);
	}
	pQ->rear = pQ->front;
	pQ->rear->pNext = NULL; 
	pQ->count = 0;
}
// 入队操作  就是在链表尾 rear插入新的节点pNew  最后count++ 
bool en_queue(PQUEUE pQ, int val)
{
    PNODE pNew = (PNODE) malloc (sizeof(NODE));
    if (!pNew)
    {
    	printf("动态内存非配失败！\n");
    	exit(-1);
	}
	pNew->data = val;
	pNew->pNext = NULL;
	pQ->rear->pNext = pNew;
	pQ->rear = pNew;
	pQ->count++;
	return true;
} 
// 队列是否空 
bool is_empty(PQUEUE pQ)
{
//	pQ->front == pQ->rear;   这样也可以 
	return pQ->count == 0; 
}
// 出队操作    从链表头节点之后的第一个有效节点  开始依次出队 
//             队列空 return false   
//             不空  定义一个临时节点temp 存放出队元素所在的节点 将要被出队的元素值赋给*pVal 
//                   if (只有一个有效节点)  将rear指向 front      最后释放临时节点的空间   count--    
bool delete_queue(PQUEUE pQ, int * pVal)
{
	if (is_empty(pQ))
	{
		printf("队列为空！ 出队失败! \n");
		return false;
	}
	else
	{
		PNODE temp = pQ->front->pNext;
		*pVal = temp->data;
		pQ->front->pNext = temp->pNext;
		if (pQ->count == 1)
		{
			pQ->front = pQ->rear;
		}
		free(temp);  
		pQ->count--;
	}
}
// 遍历操作 
void traverse_queue(PQUEUE pQ)
{
	if (is_empty(pQ))
	{
		printf("队列中没有有效数据！\n"); 
	}
	else
	{
    	PNODE p = pQ->front->pNext;     // pQ->front头节点    p代表第一个有效的节点 
    	printf("队列中的元素是：");
		while (p)
		{
	     	printf("%d   ", p->data);
			 p = p->pNext;	
		}		
		printf("\n");
    } 	
}
// 队列长度 
int length_queue(PQUEUE pQ)
{
	return pQ->count;
}
// 清空队列  定义两个临时节点  从头节点之后的第一个有效的节点开始 释放空间    
void clear_queue(PQUEUE pQ)
{
	PNODE p = pQ->front->pNext;      // 首节点  （第一个有效元素的节点） 
	PNODE q ;
	while (p)
	{
		q = p->pNext;
		free(p);
		p = q;	
	} 
	/*  上面的另外一种写法 
	PNODE p = pQ->front->pNext;      // 首节点  （第一个有效元素的节点） 
	while (p)                        // 不为空 就执行 
	{
		PNODE temp = p;
		p = p->pNext;
		free(temp);
	}
	*/ 
	
	// 当while执行完 头节点之后的都被删除了  count为0     头节点的pNext = NULL   rear指向头节点 
	pQ->count = 0;
	pQ->front->pNext = NULL;
	pQ->rear = pQ->front;
}

void destroy_queue(PQUEUE pQ)
{
    PNODE p = pQ->front->pNext;
	PNODE q;
	while (p)
	{
	 	q = p->pNext;
		free(p);
		p = q;	
	}	
	pQ->count = 0;
	pQ->front = pQ->rear = NULL;
} 
