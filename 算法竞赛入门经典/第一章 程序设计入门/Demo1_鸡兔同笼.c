#include <stdio.h>
#include <time.h>

/*
��Ŀ�� 
	��֪�����õ�����Ϊn�� ������Ϊm������n��m���������������Ŀ���õ���Ŀ�� ����޽����No answer

�������룺
    14 32
���������
    12 2
*/


// ����1��������forѭ��Ƕ�� �Ƴ�a��b   ʱ�临�Ӷ� o(n^2) 
void f1()
{
    int n = 14000, m = 32000;
    int a, b;                                    // a����  b����
    int flag = 0;                            // 0˵���޽�  
    for (a = 0; a <= n; ++a)
    {
        for (b = 0; b <= n; ++b)
        {
            if (a * 2 + b * 4 == m && a + b == n)
            {
                flag = 1;
                printf("%d  %d\n", a, b);
                break;
            }
        }
    }
    if (0 == flag)
    {
        printf("No answer\n");
    }
}
//12000  2000
//time:0.918000s


// ����2�� ��a��b��ͨ���ⷽ�������   ʱ�临�Ӷ� o(1) 
void f2()
{
    int n = 14000, m = 32000;
    int a, b;

    a = (4 * n - m) / 2;
    b = n - a;

    // �����ʱ����  ���ӡ���ֻ��С��0   
    if (m % 2 == 1 || a < 0 || b < 0)
    {
        printf("No answer\n");
    } else
    {
        printf("%d  %d\n", a, b);
    }
}
//12000  2000
//time:0.000000s

int main(void)
{
    // ���������������ʱ��  
    clock_t start, finish;
    start = clock();
    f1();
//     f2();
    finish = clock();
    printf("time:%fs\n", (double) (finish - start) / CLOCKS_PER_SEC);
    return 0;
}

/*
	�ܽ᣺
	   ���������ڽⷽ�̵��� ����������   �ܲ�Ҫ�ü���ѭ��ȥ�� �Ͳ�Ҫ��
	   �Ƚ����̵Ľ� ����� Ȼ�����ȥ�� 
*/ 
