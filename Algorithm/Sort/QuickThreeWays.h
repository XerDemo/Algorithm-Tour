////
//// Created by XerDemo on 2019/6/29.
////
//
//#ifndef ALGORITHM_QUICKTHREEWAYS_H
//#define ALGORITHM_QUICKTHREEWAYS_H
//
//#include "SortHelp.h"
//
//void __QuickSortThreeWays(int * nums, int left, int right){
//    if (left >= right){
//        return;
//    }
//    swap(left, rand() % (right - left + 1) + left);
//    int v = nums[left];
//    int i = left + 1, lt = left, gt = right+1;
//
//    while (1) {
//        if (i < gt && nums[i] < v) {
//            swap(nums, lt + 1, i);
//            lt++;
//            i++;
//        } else if (i < gt && nums[i] > v) {
//            swap(nums, i, gt - 1);
//            gt--;
//        } else if (i < gt && nums[i] == v) {
//            i++;
//        }
//        if (i == gt) {
//            break;
//        }
//    }
//    printf("v = %d ", nums[left]);
//    swap(nums, left, lt);
//    printf(" v = %d , [%d  , %d] \n", nums[left], nums[lt - 1], nums[lt]);
//    __QuickSortThreeWays(nums, left, lt);
//    __QuickSortThreeWays(nums, gt, right);
//}
//
//void QuickSortThreeWays(int * nums, int n){
//    __QuickSortThreeWays(nums, 0, n - 1);
//}
//
//
////#include <stdio.h>
////#include <stdlib.h>
////#include <time.h>
////#include "SortHelp.h"
////
////// arr[left+1...lt] < v  ; arr[lt+1...i-1] == v ; arr[gt...right] >v
////void __QuickSortThreeWays(int *arr, int left, int right)
////{
////    int i, lt, gt;
////    if (left >= right)                     // 递归结束条件
////    {
////        return;
////    }
////
////    swap(arr, left, rand() % (right - left + 1) + left);
//////    swap(&arr[left], &arr[rand() % (right - left + 1) + left]);      // 选取随机基准 与arr[left]交换
////    int v = arr[left];                                               // 基准
////
////    lt = left;           // 将初始lt代入 [left+1...lt] < v  刚好使这个区间无效
////    gt = right + 1;      // 同理 gt代入  [gt...right] >v
////    i = left + 1;        // 同理i代入    [lt+1...i-1] == v
////
////        while (1){
////
////        if (i < gt && arr[i] < v){
////            swap(arr, lt + 1, i);
////            lt++;
////            i++;
////        }
////        else if (i < gt && arr[i] > v){
////            swap(arr, i, gt - 1);
////            gt--;
////        } else if (i < gt && arr[i] == v){
////            i++;
////        }
////        if (i == gt) {
////            break;
////        }
////    }
////
//////    // i和gt还没遇上
//////    while (i < gt)
//////    {
//////        if (arr[i] < v)               // 当前元素 < 基准
//////        {
////////            swap(&arr[i], &arr[lt + 1]);
//////            swap(arr, i, lt + 1);
//////            lt++;
//////            i++;
//////        }
//////        else if (arr[i] > v)        // 当前元素 > 基准
//////        {
//////            swap(arr, i, gt - 1);
////////            swap(&arr[i], &arr[gt - 1]);
//////            gt--;                     // 注意i不动
//////        }
//////        else
//////        {                             // 等于基准
//////            i++;
//////        }
//////    }
////    // 此时i和gt已经遇上了
////    swap(arr, left, lt--);
////
////    __QuickSortThreeWays(arr, left, lt);
////    __QuickSortThreeWays(arr, gt, right);
////}
////
////
////// 统一接口
////void QuickSortThreeWays(int *arr, int n)
////{
////    srand(time(NULL));
////    __QuickSortThreeWays(arr, 0, n - 1);
////}
////
//
//#endif //ALGORITHM_QUICKTHREEWAYS_H
