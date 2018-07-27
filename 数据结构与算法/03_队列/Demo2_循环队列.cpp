#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

typedef struct queue{
	int data[MAXSIZE];
	int front;								//  ��ͷָ��  ʼ��ָ���ͷԪ�ص�ǰһ��λ��
	int rear;								//  ��βָ��  ʼ��ָ���β���һ��Ԫ��
}cycleQueue;
/*
     ���Ƚ��ȳ���   ����ͼ �� ������ 
	˳�������ѭ�����е�����(ʹ��ѭ������)
		ѭ�����У�1.�жϿ� pQ->front == pQ->rear (0)
			  2.�ж��� (pQ->rear + 1) % ���鳤�� == pQ->front
			  3.front   rear  ���Ǵ� 0��ʼ
			  4.������ֶ����������ǿ�      
		     	����1����������һ������ �䵱������ n �� n == 0 ���п�  �� n == MAXSIZE(���鳤��) ������   
			 	����2������һ���ռ�Ԫ��  �����������ֻ�ܴ��� ���鳤��-1 ��Ԫ��   
			  5. �ж϶��г���   
			               (pQ->rear - pQ->front + MAXSIZE ) % MAXSIZE
			 	
		˳����У�1.�жϿ�   pQ->front == pQ->rear
			  2.�ж���   MAXSIZE - 1 == pQ->rear
			  3.���ӵ�Ԫ�ص�λ�ã�����Ԫ�ز����ᱻɾ��ֻ��front�Ƶ��� �ᱻһֱռ�� �� ��ѭ�����н�����������
			  4.˳����� front rear ��-1��ʼ             ѭ�����У� front  rear ��0��ʼ 
			  5. �ж϶��г���   pQ->rear - pQ->front 
*/ 
void init_queue(cycleQueue * pQ);	 									// ���������ķ�ʽ 
cycleQueue * create_queue();											// malloc "�ڿ�"�ķ�ʽ 									
bool full_queue(cycleQueue * pQ);										// �ж�ѭ�������Ƿ���										
bool empty_queue(cycleQueue * pQ);										// �ж�ѭ�������Ƿ���
bool out_queue(cycleQueue *pQ, int * pVal);                             // ���� 
bool in_queue(cycleQueue * pQ, int val);								// ��� 
int length_queue(cycleQueue * pQ);										// ���г��� 
void traverse_queue(cycleQueue * pQ);									// ���� 

int main (void)
{
	// ���������ķ�ʽ 
	cycleQueue Q;
	init_queue(&Q);
	
	// malloc "�ڿ�"�ķ�ʽ 
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
