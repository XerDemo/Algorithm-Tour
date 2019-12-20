//
//#ifndef ALGORITHM_QUICKSORTTWOWAYS_H
//#define ALGORITHM_QUICKSORTTWOWAYS_H
//
//#include "SortHelp.h"
//#include <iostream>
//
//using namespace std;
//
//
//int partion(int * num, int left, int right) {
//    double sum = 0;
//    for (int k = left; k <= right ; ++k) {
//        sum += num[k];
//    }
//    int v = sum / (right - left + 1);
//    int i = left, j = right;
//    while (1) {
//        while (i <= j && num[i] < v) {
//            i++;
//        }
//        while (i <= j && num[j] > v){
//            j--;
//        }
//        if (i > j){
//            break;
//        }
//        swap(num[i], num[j]);
//        i++;
//        j--;
//    }
//    return j;
////    if (v < num[left]) { // 放入(j, right]
////        swap(num[left], num[j]);
////        j--;
////        return j + 1;
////    } else{
////        swap(num[left], num[i]);
////        i++;
////        return i - 1;
////    }
//
//}
//
//void __quickSortTwoWays(int *nums, int left, int right) {
//    if (left > right) {
//        return;
//    }
//    int p = partion(nums, left, right);
//
//    cout << "p :" << p << endl;
//    printArray(nums, 10);
//    __quickSortTwoWays(nums, left, p);
//    __quickSortTwoWays(nums, p + 1, right);
//}
//
//void QuickSortTwoWays(int *nums, int n) {
//    __quickSortTwoWays(nums, 0, n - 1);
//}
//
//
//
//#endif //ALGORITHM_QUICKSORTTWOWAYS_H
