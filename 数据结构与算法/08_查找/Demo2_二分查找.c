#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE  10000
/**
 *   ���ֲ���
 *        1.����
 *        2.����
 *    ʱ�临�Ӷ� o(log2^n)
 */

int main(void)
{

    clock_t start, finish;
    start = clock();

    int i,left, right, mid,count, val;
    int arr[MAXSIZE];
    // ������ ��0-99�����ʼ��
    for (i=0; i<MAXSIZE; ++i)
    {
        arr[i] = i;
    }

    printf("������Ҫ���ҵ�ֵ��");
    scanf("%d",&val);

    left = 0;
    right = MAXSIZE - 1;
    while (left <= right)
    {
        mid = (left + right)/2;
//        printf("--------------------\n");
//        printf("left: %d\n", left);
//        printf("mid: %d\n", mid);
//        printf("right: %d\n", right);
//        printf("--------------------\n");
        if (arr[mid] < val)
        {
            left = mid + 1;
        } else if (arr[mid] > val)
        {
            right = mid - 1;
        } else{
            break;
        }
    }

    if (left > right)
    {
        printf("��Ԫ��δ�ҵ���\n");
        printf("������%d�αȽ�\n", count);
        printf("�ɽ��������뵽��%dλ����\n",left+1);    // left,mid,right��ʱָ��ͬһλ��  mid+1 right+1 �Կ�
    } else{
        printf("��Ԫ���������е��±�Ϊ%d\n", mid);
    }

    finish = clock();
    printf("��ʱ��%fms\n", (double)(finish-start)/CLOCKS_PER_SEC );
    return 0;
}
