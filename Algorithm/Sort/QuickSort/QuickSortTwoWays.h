//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include "SortHelp.h"
//#include <stack>
//
//using namespace std;
//
//// 对arr[left...right]部分进行partition操作
//// 返回排好序时基准所在的位置p,使得 arr[left+1...i) <= v; arr(j...right] >= v
//int __partitionTwoWays(int *arr, int left, int right)
//{
//    int i, j;
//    swap(&arr[left], &arr[rand() % (right - left + 1) + left]);   // 选取随机基准 与arr[left]交换
//    int v = arr[left];                                            // 基准 此时基准已经时交换了的随机数
//
//    // arr[left+1...i) <= v; arr(j...right] >= v
//    i = left + 1, j = right;                                      // i初始化为left+1 刚好arr[left+1..i)无效 j同理
//    while (1)
//    {
//        // i 从左向右扫描 遇到比基准小的元素 i++
//        // 注意这里的边界, arr[i] < v, 不能是arr[i] <= v    思考一下为什么?
//        while (i <= right && arr[i] < v)        // 写成i <= j 也可以
//        {
//            i++;
//        }
//
//        // j 从右向左扫描 遇到比基准大的元素 j--
//        // 注意这里的边界, arr[j] > v, 不能是arr[j] >= v 思考？
//        while (j >= left + 1 && arr[j] > v)     // 写成j >= i 也可以
//        {
//            j--;
//        }
//
//        // 两者相遇时 按照之前的动画逻辑  相遇时 i>j 用数据加图来体会
//        if (i > j)
//        {
//            break;
//        }
//        swap(&arr[i], &arr[j]);         // i,j两者对应元素交换
//        i++;
//        j--;
//    }
//    swap(&arr[left], &arr[j]);          // 把基准放到 排好序应该在的位置 注意是与j交换不是i 画图体会
//    return j;
//
///*
//	比如数组 1,0,0, ..., 0, 0
//	a. 对于arr[i]<v和arr[j]>v的方式，第一次partition得到的分点是数组中间；
//	b. 对于arr[i]<=v和arr[j]>=v的方式，第一次partition得到的分点是数组的倒数第二个。
//	这是因为对于连续出现相等的情况，a方式会交换i和j的值；而b方式则会将连续出现的这些值归为其中一方，使得两棵子树不平衡
//*/
//}
//
//// 对arr[left, right]进行快速排序
//void __QuickSortTwoWays(int *arr, int left, int right)
//{
//    if (right - left <= 15)                      // 递归结束条件
//    {
//        InsertionSort(arr, left, right);
//        return;
//    }
//    int p = __partitionTwoWays(arr, left, right);      // 排好序后 基准所在位置的索引
//    __QuickSortTwoWays(arr, left, p - 1);              // 对左子序列进行快排
//    __QuickSortTwoWays(arr, p + 1, right);             // 对右子序列进行快排
//}
//
//// 非递归实现快速排序
//void quickSort(int *arr, int left, int right){
//    if (left >= right) {
//        return;
//    }
//    stack<int> s;
//    s.push(right);
//    s.push(left);
//    while (s.size() != 0) {
//        int i = s.top();
//        s.pop();
//        int j = s.top();
//        s.pop();
//
//        if (i < j) {
//            int p = __partitionTwoWays(arr, i, j);
//            if (p > i) {
//                s.push(p - 1);
//                s.push(i);
//            }
//            if (j > p) {
//                s.push(j);
//                s.push(p + 1);
//            }
//        }
//    }
//}
//
//
//// 统一接口
//void QuickSortTwoWays(int *arr, int n)
//{
//    srand(time(NULL));
////    __QuickSortTwoWays(arr, 0, n - 1);
//    quickSort(arr, 0, n - 1);
//}
//
