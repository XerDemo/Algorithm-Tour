#include <stdio.h>
#include <time.h>

int main(void)
{
    int a, b, c;
    int temp;
    scanf("%d %d %d", &a, &b, &c);

    // 按从小到大的顺序排序  a  b  c
    if (a > b)
    {
        temp = a;
        a = b;
        b = a;
    }
    if (a > c)
    {
        // 此种交换 两个数的方式 不推荐
        a = a ^ c;
        c = a ^ c;
        a = a ^ c;
    }
    /*** 到了这里 a <= b ***/
    if (b > c)
    {
        // 此种交换 两个数的方式 不推荐
        b = b + c;
        c = b - c;
        b = b - c;
    }

    /*** 此时 a <= b  && b <= c***/
    printf("%d %d %d\n", a, b, c);
    return 0;
}


