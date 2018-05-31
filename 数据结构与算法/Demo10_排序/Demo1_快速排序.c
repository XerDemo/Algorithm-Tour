#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 8


void quickSort(int * arr, int left, int right);                         // ��������
int partition(int arr[], int left, int right);                          // ����һ�˿���������׼�������е�λ�ã���ʱ�Ѿ�С��Ԫ�ط��ڻ�׼��࣬���Ԫ���Ҳ�

int main()
{
    int i;
    int arr[MAXSIZE] = {70, 75, 69, 32, 88, 18, 16, 58};
    quickSort(arr, 0, MAXSIZE - 1);

    printf("���������\n");
    for (i = 0; i < MAXSIZE; ++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*
 *  ��������
      ����˼�룺 ��ѡ���������е�һ��Ԫ��(ͨ��ѡȡ���ǵ�һ��Ԫ��)��Ϊ��׼(Ҳ������privot),���ջ�׼�Ĵ�С���������зֳ���������������(�Ի�׼Ϊ�ο�)
               �Ȼ�׼С���������ڻ�׼��ߣ��Ȼ�׼������������ڻ�׼�ұߣ�Ȼ��ݹ�������������еݹ������Ƶķ�����������
      ����������
           �������Ԫ�ص��½���Ͻ�ֱ�Ϊleft��right��arr[left]������Ԫ��(������ѡȡ���ǵ�һ��Ԫ��)�����������������
        1.	���Ƚ�arr[keft]�е�Ԫ�ر��浽pivot������
        2.	��right������(��������)�����arr[right]���ڵ��ڻ�׼��right-1 ֱ�� arr[right]<��׼,���临�Ƶ�left����λ�ã�Ȼ��left+1 ��arr[left] = arr[right] ; left++
        3.	��left��ʼ������(��������)��arr[left]С�ڵ��ڻ�׼��left + 1 ֱ�� arr[left] > ��׼,���临�Ƶ�right����λ�ã�Ȼ��right-1 ��arr[right] = arr[left] ; right--
        4.	�ظ�����2��3ֱ��left == rightΪֹ(Ҳ������ָ������)����ʱ��pivot�е�ֵ�Żص�left��right������λ�ã�һ�˿����������
 */

void quickSort(int * arr, int left, int right)
{
    static  int num = 0;                                         // ��¼����
    int privotPosition, i;                                       // ��׼�������е�λ��(����)
    if (left < right)
    {
        // ����partition()���ػ�׼��λ�ò����ڷ���ʱ�Ѿ�ͨ���ú�����С��Ԫ�ط��ڻ�׼��࣬���Ԫ���Ҳ�
        privotPosition = partition(arr, left, right);
        // ��ӡ��1-n�˿�������Ľ��
        printf("��%d�˿���������:\n", ++num);
        for (i = 0; i < MAXSIZE; ++i)
        {
            printf("%d  ", arr[i]);
        }
        printf("\n");

        quickSort(arr, left, privotPosition-1);                 // ���������еݹ���п�������
        quickSort(arr, privotPosition + 1, right);              // ���������еݹ���п�������
    }
}

// ����һ�˿���������׼�������е�λ�ã���ʱ�Ѿ�С��Ԫ�ط��ڻ�׼��࣬���Ԫ���Ҳ�
int partition(int arr[], int left, int right)
{
    int privot = arr[left];                                             // ������ѡȡ������ÿһ�����еĵ�һ��Ԫ����Ϊ��׼ ���ѡȡ:ȡ ��һ��Ԫ�� �м�һ��Ԫ�� ���һ��Ԫ�ص���λ��
    while (left < right)
    {
        // ��right������(��������)�����arr[right]���ڵ��ڻ�׼��right-1
        while (left < right && arr[right] >= privot)
        {
            right--;
        }
        // ֱ�� arr[right]<��׼,���临�Ƶ�left����λ�ã�Ȼ��left+1 ��arr[left] = arr[right] ; left++
        if (left < right)
        {
            arr[left++] = arr[right];
        }

        // ��left��ʼ������(��������)��arr[left]С�ڵ��ڻ�׼��left + 1
        while (left < right && arr[left] <= privot)
        {
            left++;
        }
        // ֱ�� arr[left] > ��׼,���临�Ƶ�right����λ�ã�Ȼ��right-1 ��arr[right] = arr[left] ; right--
        if (left < right )
        {
            arr[right--] = arr[left];
        }
    }
    // �ظ�����2��3ֱ��left == rightΪֹ(Ҳ������ָ������)����ʱ��pivot�е�ֵ�Żص�left��right������λ�ã�һ�˿����������
    arr[left] = privot;
    return left;
}



