#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100000000                      // ��������ռ��������
/*
˳����Ҽ�������˳���Ҳ����������   ʱ�临�Ӷ� o(n) 

����˼�룺�ӱ��һ�˿�ʼ��˳��ɨ�����Ա����ΰ�������ֵ��ؼ��֣�key�����Ƚϣ��������Ƚϳɹ�������������Ԫ�������Ա��е�λ�ã�
         ���������Ա������ϣ���δ�ҵ������ֵ��ͬ�Ĺؼ��֣������ʧ�ܣ�����ʧ����Ϣ��

����Ԫ�ش��±�Ϊ1�����鵥Ԫ��ʼ��ţ�0�ŵ�Ԫ��Ϊ����ڣ�������Ŵ����ҵ�ֵ��

�����ڣ������ҵ�����Ԫ�ض�������Ԫ�ص�����N�����ʱ����Բ���"˳�����" 
 */

double seqFindMinitor();                       // ���ڱ�
double seqFind();                              // �����ڱ�

int main(void)
{

    int i;
    double sum = 0;

//    for (i = 0; i < 20; ++i)
//    {
//        sum += seqFindMinitor();
//    }
//    printf("���ڱ��ܹ����ѣ�%f s\n", sum);
//    printf("���ڱ�ƽ�����ѣ�%f s\n", sum / 30);


    for (i = 0; i < 20; ++i)
    {
        sum += seqFind();
    }
    printf("�����ڱ��ܹ����ѣ�%f s\n", sum);
    printf("�����ڱ�ƽ�����ѣ�%f s\n", sum / 30);

    return 0;
}

// ���������
double seqFind()
{
    clock_t start, finish;
    start = clock();

    long *data = (long *) malloc(sizeof(long) * MAXSIZE);
    long key = 2;                                 // �����ҵĹؼ���
    long i;
    // ��data�����ʼ��
    for (i = 0; i < MAXSIZE; ++i)
    {
        data[i] = i;
    }

    // ��ʼ����  �����ҴӺ���ǰ��
    for (i = MAXSIZE - 1; i >= 0; --i)          // ʱ�临�Ӷ� o(n) 
    {
        if (key == data[i])
        {
            printf("key = %ld ��data�����е�index�� %ld\n", key, i);
            break;
        }
    }

    finish = clock();
//    printf("�����ڱ�Time��%f s\n", (double) (finish - start) / CLOCKS_PER_SEC);
    return (double) (finish - start) / CLOCKS_PER_SEC;
}

// �������
double seqFindMinitor()
{
    clock_t start, finish;
    start = clock();

    long *data = (long *) malloc(sizeof(long) * MAXSIZE);
    long key = 2;                                 // �����ҵĹؼ���
    long i;
    // ��data�����ʼ��
    for (i = 0; i < MAXSIZE; ++i)             
    {
        data[i] = i;
    }

    /****************************************************************/
    // ��ʼ����  �����ҴӺ���ǰ��
    data[0] = key;
    // �벻���ڱ���� ��������һ���ж�����i>=0  �ӿ����ٶ�
    for (i = MAXSIZE - 1; key != data[i]; --i);   // ʱ�临�Ӷ� o(n) 
    // forѭ������ ���ʱkey == data[i]  ���i==0 ˵��û�ҵ�
    if (i == 0)
    {
        printf("no found!\n");
    } else
    {
        printf("key = %ld ��data�����е�index�� %ld\n", key, i);
    }
    /*****************************************************************/
    finish = clock();
//    printf("���ڱ�Time��%f s\n", (double) (finish - start) / CLOCKS_PER_SEC);
    return (double) (finish - start) / CLOCKS_PER_SEC;
}




