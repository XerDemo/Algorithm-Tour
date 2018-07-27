
#include <stdio.h>
#include <stdlib.h>
/*************************��ʽ���С�������ʵ��*******************************************/
typedef struct Node{
	int data;
	struct Node * pNext;
}NODE, *PNODE;

typedef struct Queue{
    PNODE front;                // ��ͷָ�� 
	PNODE rear;                 // ��βָ�� 
	int count;	                // ������ 
}QUEUE, *PQUEUE;

void init_queue(PQUEUE pQ);                                   // ��ʼ�� ���� 
bool en_queue(PQUEUE pQ, int val);                            // ��� 
bool is_empty(PQUEUE pQ);                                     // �ж϶����Ƿ�� 
void traverse_queue(PQUEUE pQ);                               // ���� 
bool delete_queue(PQUEUE pQ, int * pVal);                     // ����             
int length_queue(PQUEUE pQ);                                  // ���г��� 
void clear_queue(PQUEUE pQ);                                  // ��ն��� 
void destroy_queue(PQUEUE pQ);                                // ���ٶ��� 

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
		printf("����Ԫ�أ�%d\n", val);
	}
	en_queue(&Q,4);
	printf("���г��ȣ�%d\n", length_queue(&Q));
	traverse_queue(&Q);
	
	printf("��ն��У�\n");
	clear_queue(&Q);
	printf("���г��ȣ�%d\n", length_queue(&Q));
	traverse_queue(&Q);
	
	en_queue(&Q,10);
	en_queue(&Q,11);
	printf("���г��ȣ�%d\n", length_queue(&Q));
	traverse_queue(&Q);
	
	printf("���ٶ��У�\n");
	destroy_queue(&Q);
	printf("Q.front = %p   Q.rear = %p\n", Q.front, Q.rear);
	return 0;	
} 

// ��ʼ��    1.һ��ʼû��Ԫ��ʱ ��Ҫ��һ��ͷ�ڵ㷽����� ��ʱfront��rear��ָ��ͷ���  rear�������һ���ڵ� rear->pNext == NULL  count ==0 
void init_queue(PQUEUE pQ)
{
	pQ->front = (PNODE) malloc (sizeof(NODE));
	if (!pQ->front)
	{
		printf("��̬�ڴ����ʧ��!\n");
		exit(-1);
	}
	pQ->rear = pQ->front;
	pQ->rear->pNext = NULL; 
	pQ->count = 0;
}
// ��Ӳ���  ����������β rear�����µĽڵ�pNew  ���count++ 
bool en_queue(PQUEUE pQ, int val)
{
    PNODE pNew = (PNODE) malloc (sizeof(NODE));
    if (!pNew)
    {
    	printf("��̬�ڴ����ʧ�ܣ�\n");
    	exit(-1);
	}
	pNew->data = val;
	pNew->pNext = NULL;
	pQ->rear->pNext = pNew;
	pQ->rear = pNew;
	pQ->count++;
	return true;
} 
// �����Ƿ�� 
bool is_empty(PQUEUE pQ)
{
//	pQ->front == pQ->rear;   ����Ҳ���� 
	return pQ->count == 0; 
}
// ���Ӳ���    ������ͷ�ڵ�֮��ĵ�һ����Ч�ڵ�  ��ʼ���γ��� 
//             ���п� return false   
//             ����  ����һ����ʱ�ڵ�temp ��ų���Ԫ�����ڵĽڵ� ��Ҫ�����ӵ�Ԫ��ֵ����*pVal 
//                   if (ֻ��һ����Ч�ڵ�)  ��rearָ�� front      ����ͷ���ʱ�ڵ�Ŀռ�   count--    
bool delete_queue(PQUEUE pQ, int * pVal)
{
	if (is_empty(pQ))
	{
		printf("����Ϊ�գ� ����ʧ��! \n");
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
// �������� 
void traverse_queue(PQUEUE pQ)
{
	if (is_empty(pQ))
	{
		printf("������û����Ч���ݣ�\n"); 
	}
	else
	{
    	PNODE p = pQ->front->pNext;     // pQ->frontͷ�ڵ�    p�����һ����Ч�Ľڵ� 
    	printf("�����е�Ԫ���ǣ�");
		while (p)
		{
	     	printf("%d   ", p->data);
			 p = p->pNext;	
		}		
		printf("\n");
    } 	
}
// ���г��� 
int length_queue(PQUEUE pQ)
{
	return pQ->count;
}
// ��ն���  ����������ʱ�ڵ�  ��ͷ�ڵ�֮��ĵ�һ����Ч�Ľڵ㿪ʼ �ͷſռ�    
void clear_queue(PQUEUE pQ)
{
	PNODE p = pQ->front->pNext;      // �׽ڵ�  ����һ����ЧԪ�صĽڵ㣩 
	PNODE q ;
	while (p)
	{
		q = p->pNext;
		free(p);
		p = q;	
	} 
	/*  ���������һ��д�� 
	PNODE p = pQ->front->pNext;      // �׽ڵ�  ����һ����ЧԪ�صĽڵ㣩 
	while (p)                        // ��Ϊ�� ��ִ�� 
	{
		PNODE temp = p;
		p = p->pNext;
		free(temp);
	}
	*/ 
	
	// ��whileִ���� ͷ�ڵ�֮��Ķ���ɾ����  countΪ0     ͷ�ڵ��pNext = NULL   rearָ��ͷ�ڵ� 
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
