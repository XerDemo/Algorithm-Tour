//
// Created by XerDemo on 2018/6/26.
//

#ifndef PROGRAM_CIRQUEUE_H
#define PROGRAM_CIRQUEUE_H

#include <stdio.h>
#include <stdlib.h>

#include "MazeData.h"
#define MAXSIZE 50

typedef struct queue{
    Node data[MAXSIZE];
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

// ��������
cycleQueue * create_queue()
{
    cycleQueue * pQ = (cycleQueue * ) malloc (sizeof(cycleQueue));
    if (!pQ)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    // ��ʼ����ͷ ��βָ�� 
    pQ->rear = 0;
    pQ->front = 0;
}

// �ж϶����Ƿ��� 
int isFullQueue(cycleQueue * pQ)
{
    return (pQ->rear+1)%MAXSIZE == pQ->front;
}

// �ж϶����Ƿ�Ϊ�� 
int isEmptyQueue(cycleQueue * pQ)
{
    return pQ->front == pQ->rear;
}

// ��� 
void enQueue(cycleQueue * pQ, Node p)
{
	// ��������� 
    if (isFullQueue(pQ))
    {
        printf("cycleQueue is full! in_queue is failed!\n");
    } else{
        pQ->rear = (pQ->rear + 1) % MAXSIZE;
        pQ->data[pQ->rear] = p;
    }

}

// ���� 
Node outQueue(cycleQueue *pQ)
{
    if (isEmptyQueue(pQ))
    {
        printf("cycleQueue is empty! out_queue is failed!\n");
    } else{
        pQ->front = (pQ->front + 1) % MAXSIZE;
        return pQ->data[pQ->front];
    }
}

// ���г��� 
int lengthQueue(cycleQueue * pQ)
{
    return (pQ->rear - pQ->front + MAXSIZE ) % MAXSIZE;
}

// �������� 
void traverseQueue(cycleQueue * pQ)
{
    if (isEmptyQueue(pQ))
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

#endif //PROGRAM_CIRQUEUE_H

