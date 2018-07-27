#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10                      // ���г�ʼ����   ����������realloc
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
typedef struct queue{
    int data[MAXSIZE];
    int front;								//  ��ͷָ��  ʼ��ָ���ͷԪ�ص�ǰһ��λ��
    int rear;								//  ��βָ��  ʼ��ָ���β���һ��Ԫ��
}seqQueue;

void init_queue(seqQueue * pQ);             //  ��̬  �����ķ�ʽ
seqQueue * create_queue();					//  ��̬ maoolc "�ڿ�"
int full_queue(seqQueue * pQ);				// �ж�˳������Ƿ���
int empty_queue(seqQueue * pQ);			    // �ж�˳������Ƿ��
int in_queue(seqQueue * pQ, int val);		// ���
int out_queue(seqQueue * pQ, int * pVal);   // ����
void traverse_queue(seqQueue * pQ);			// ���� ����Ԫ��
int length_queue(seqQueue * pQ);			// ����Ԫ�صĳ���

int main (void)
{
    // ��̬ �ú��������ķ�ʽ
    seqQueue Q;
    init_queue(&Q);
    // malloc �� "�ڿ�"�ķ�ʽ   (�ٴ�ѡ������)
    seqQueue * pQ = create_queue();
    int val;
    in_queue(pQ, 1);
    if (out_queue(pQ, &val))
    {
        printf("out_queue�� %d \n",val);
    }

    if (out_queue(pQ, &val))
    {
        printf("out_queue�� %d \n",val);
    }
    in_queue(pQ, 3);
    in_queue(pQ, 5);
    in_queue(pQ, 2);

    if (out_queue(pQ, &val))
    {
        printf("out_queue�� %d \n",val);
    }
    in_queue(pQ, 4);

    printf("seqQueue length is : %d\n", length_queue(pQ));
    traverse_queue(pQ);
    printf("seqQueue length is : %d\n", length_queue(pQ));
    return 0;
}

void init_queue(seqQueue * pQ)
{
    pQ->front = -1;
    pQ->rear = -1;
}

seqQueue * create_queue()
{
    seqQueue * pQ = (seqQueue * ) malloc (sizeof (seqQueue));
    if (!pQ)
    {
        printf("malloc is failed!\n");
        exit(-1);
    }
    pQ->front = -1;
    pQ->rear = -1;
    return pQ;
}

// ��rear�����һ��Ԫ�� �Ѿ����������һ��λ��ʱ ��
int full_queue(seqQueue * pQ)
{
    // return pQ->rear == MAXSIZE - 1;  ���Ƽ�����д�� ����Ҵ���� = ���� == ����д�����ᱨ�� �൱�ڸ�������ֵ
    return MAXSIZE - 1 == pQ->rear;     // �Ƽ�����д��  ���� �����ܱ���ֵ ���д�� = �ᱨ��
}

// ��front �� rear ���ʱ  ��
int empty_queue(seqQueue * pQ)
{
    return pQ->front == pQ->rear;
}

// ��� ֻ����βָ�� rear �й�
int in_queue(seqQueue * pQ, int val)
{
    if (full_queue(pQ))
    {
        printf("seqQueue is full! \n");
        return -1;
    }
    pQ->data[++pQ->rear] = val;        // ps: ��++
    return 1;
}

// ���� �����е�Ԫ�� ��û�б�ɾ��  ֻ��front�ƶ��˶���
// ���� ֻ����ͷָ�� front �й�
int out_queue(seqQueue * pQ, int * pVal)
{
    if (empty_queue(pQ))
    {
        printf("seqQueue is empty! out_queue is exit!\n");
        return -1;
    }
    *pVal = pQ->data[++pQ->front];
    return 1;
}

void traverse_queue(seqQueue * pQ)
{
    if (empty_queue(pQ))
    {
        printf("seqQueue is empty! traverse_queue is exit!\n");
        return;
    }
    printf("seqQueue is : ");
    // �мǣ� Ҫ����һ�� i �� ����pQ->front  �����Ͳ�ֱ���޸�pQ->front  ֱ���޸�pQ->front �ᵼ�� pQ->front��ֵ�ı� ��������������õ�pQ->front��ֵʱ���Ǵ�-1��ʼ
    int i = pQ->front;
    while (i != pQ->rear)
    {
        printf(" %d  ", pQ->data[++i]);
    }
    printf("\n");

}

int length_queue(seqQueue * pQ)
{
    return pQ->rear - pQ->front;
}
