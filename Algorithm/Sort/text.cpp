//#include <stdio.h>
//
//#include<stdio.h>
//#include <iostream>
//
//using namespace std;
//
////void quicksort(int A[], int low, int high) {
////    if (low > high) {
////        return;
////    }
////
////
////    int i, j, temp ;
////    double ave, sum = 0.0;
////
////    for (i = low; i <= high; i++) {
////        sum += A[i];
////    }
////    i = low;
////    j = high;
////    ave = sum / (high - low + 1);
////    printf("ave = %lf    ", ave);
////
////    while (i <= j) {
////        while (A[i] < ave && i <= j) ++i;
////        while (A[j] > ave && i <= j) --j;
////        if (i < j) {
////            temp = A[i];
////            A[i] = A[j];
////            A[j] = temp;
////            i++;
////            j--;
////        }
////    }
////
////    printf("i = %d    j = %d\n", i, j);
////    if (i < high && j > low) {
////        quicksort(A, low, j);
////        quicksort(A, i, high);
////    }
////}
//void quicksort(int A[], int low, int high) {
//    if (low > high) {
//        return;
//    }
//
//
//    int i, j, temp;
//    double ave, sum = 0.0;
//
//    for (i = low; i <= high; i++) {
//        sum += A[i];
//    }
//    i = low;
//    j = high;
//    ave = sum / (high - low + 1);
//    printf("ave = %lf    ", ave);
//
//    while (1) {
//        while (A[i] < ave && i <= j) ++i;
//        while (A[j] > ave && i <= j) --j;
//        if (i > j){
//            break;
//        }
//        swap(A[i], A[j]);
//        i++;
//        j--;
//    }
//
//    printf("i = %d    j = %d\n", i, j);
//    if (i < high && j > low) {
//        quicksort(A, low, j);
//        quicksort(A, i, high);
//    }
//}
//
//int main() {
//    int num[5] = {1, 2, 5, 8, 1};
//    for (int i = 0; i < 5; ++i) {
//        printf("%d  ", num[i]);
//    }
//    printf("\n");
//
//    quicksort(num, 0, 4);
//    for (int i = 0; i < 5; ++i) {
//        printf("%d  ", num[i]);
//    }
//    printf("\n");
//    return 0;
//}