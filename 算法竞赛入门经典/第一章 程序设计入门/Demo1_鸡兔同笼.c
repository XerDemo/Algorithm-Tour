#include <stdio.h>
#include <time.h>

/*
题目： 
	已知鸡和兔的数量为n， 总腿数为m。输入n和m，依次输出鸡的数目和兔的数目。 如果无解输出No answer

样例输入：
    14 32
样例输出：
    12 2
*/


// 方法1：用两个for循环嵌套 推出a，b   时间复杂度 o(n^2) 
void f1()
{
    int n = 14000, m = 32000;
    int a, b;                                    // a：鸡  b：兔
    int flag = 0;                            // 0说明无解  
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


// 方法2： 将a和b先通过解方程算出来   时间复杂度 o(1) 
void f2()
{
    int n = 14000, m = 32000;
    int a, b;

    a = (4 * n - m) / 2;
    b = n - a;

    // 如果腿时奇数  兔子、鸡只数小于0   
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
    // 用来计算程序运行时间  
    clock_t start, finish;
    start = clock();
    f1();
//     f2();
    finish = clock();
    printf("time:%fs\n", (double) (finish - start) / CLOCKS_PER_SEC);
    return 0;
}

/*
	总结：
	   遇到类似于解方程的题 即凑数的题   能不要用吉层循环去套 就不要用
	   先将方程的解 解出来 然后带进去算 
*/ 
