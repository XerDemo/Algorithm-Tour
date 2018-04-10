#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10                      // 队列初始容量   不够可以用realloc
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
typedef struct queue{
    int data[MAXSIZE];
    int front;								//  队头指针  始终指向对头元素的前一个位置
    int rear;								//  队尾指针  始终指向队尾最后一个元素
}seqQueue;

void init_queue(seqQueue * pQ);             //  静态  声明的方式
seqQueue * create_queue();					//  动态 maoolc "挖坑"
int full_queue(seqQueue * pQ);				// 判断顺序队列是否满
int empty_queue(seqQueue * pQ);			    // 判断顺序队列是否空
int in_queue(seqQueue * pQ, int val);		// 入队
int out_queue(seqQueue * pQ, int * pVal);   // 出队
void traverse_queue(seqQueue * pQ);			// 遍历 队列元素
int length_queue(seqQueue * pQ);			// 队列元素的长度

int main (void)
{
    // 静态 用函数声明的方式
    seqQueue Q;
    init_queue(&Q);
    // malloc 用 "挖坑"的方式   (再此选用这种)
    seqQueue * pQ = create_queue();
    int val;
    in_queue(pQ, 1);
    if (out_queue(pQ, &val))
    {
        printf("out_queue： %d \n",val);
    }

    if (out_queue(pQ, &val))
    {
        printf("out_queue： %d \n",val);
    }
    in_queue(pQ, 3);
    in_queue(pQ, 5);
    in_queue(pQ, 2);

    if (out_queue(pQ, &val))
    {
        printf("out_queue： %d \n",val);
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

// 当rear即最后一个元素 已经到数组最后一个位置时 满
int full_queue(seqQueue * pQ)
{
    // return pQ->rear == MAXSIZE - 1;  不推荐此种写法 如果我打的是 = 不是 == 此种写法不会报错 相当于给变量赋值
    return MAXSIZE - 1 == pQ->rear;     // 推荐此种写法  常数 不可能被赋值 如果写成 = 会报错
}

// 当front 跟 rear 相等时  空
int empty_queue(seqQueue * pQ)
{
    return pQ->front == pQ->rear;
}

// 入队 只跟队尾指针 rear 有关
int in_queue(seqQueue * pQ, int val)
{
    if (full_queue(pQ))
    {
        printf("seqQueue is full! \n");
        return -1;
    }
    pQ->data[++pQ->rear] = val;        // ps: 先++
    return 1;
}

// 出队 数组中的元素 并没有被删除  只是front移动了而已
// 出队 只跟队头指针 front 有关
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
    // 切记： 要定义一个 i 来 保存pQ->front  这样就不直接修改pQ->front  直接修改pQ->front 会导致 pQ->front的值改变 如果有其他函数用到pQ->front的值时不是从-1开始
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
