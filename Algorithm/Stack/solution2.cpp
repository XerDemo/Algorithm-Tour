#include <stdlib.h>
#include <stdio.h>

#define MaxSize 20


//int p(int n, int x){
//    if (n == 0){
//        return 1;
//    }
//    if (n == 1) {
//        return 2 * x;
//    }
//    return 2 * x * p(n - 1, x) - 2 * (n - 1) * p(n - 2, x);
//}

//double p(int n, double x) {
//    typedef struct stack{
//        int n;
//        int val;
//    }st[MaxSize];
//
//    int top = -1;
//}


double p(int n, double x){
    struct stack{
        int no;
        double  val;
    }st[MaxSize];

    int top = -1, i;
    double fv1 = 1, fv2 = 2*x;

    for (i = n; i >= 2; --i) {
        top++;
        st[top].no = i;
        printf("%d  \n", st[top].no);
    }

    while (top >= 0) {
        st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }
    if(n==0){
        return fv1;
    }
    return fv2;
}



int main(void) {
    printf("%lf\n", p(4, 2));
    return 0;
}