#include <stdio.h>
#include <time.h>

int main(void)
{
    int a, b, c;
    int temp;
    scanf("%d %d %d", &a, &b, &c);

    // ����С�����˳������  a  b  c
    if (a > b)
    {
        temp = a;
        a = b;
        b = a;
    }
    if (a > c)
    {
        // ���ֽ��� �������ķ�ʽ ���Ƽ�
        a = a ^ c;
        c = a ^ c;
        a = a ^ c;
    }
    /*** �������� a <= b ***/
    if (b > c)
    {
        // ���ֽ��� �������ķ�ʽ ���Ƽ�
        b = b + c;
        c = b - c;
        b = b - c;
    }

    /*** ��ʱ a <= b  && b <= c***/
    printf("%d %d %d\n", a, b, c);
    return 0;
}


