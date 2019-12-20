//#include <stdlib.h>
//#include <stdio.h>
//#include<iostream>
//#include <memory.h>
//
//#define  maxsize  205
//using namespace std;
//
//int p[maxsize];
//int dp[maxsize][maxsize];
//
//int main(void) {
//    int n;
//    scanf("%d", &n);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d %d", &p[i], &p[i + 1]);
//    }
//    for (int i = 1; i <= n; ++i) {
//        dp[i][i] = 0;
//    }
//
//    for (int r = 2; r <= n; ++r) {
//        for (int i = 1; i <= n-r+1; ++i) {
//            int j = i + r -1;
////            dp[i][j] = 9999999;
//            dp[i][j] = dp[i + 1][j] + p[i - 1] * p[i] * p[j];
//            for (int k = i; k <= j-1; ++k) {
//                int temp = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
//                dp[i][j] = min(dp[i][j], temp);
//            }
//        }
//    }
//    printf("%d", dp[1][n]);
//    return 0;
//}
