//#include <stdio.h>
//#include <stdlib.h>
//#define N 100
//
//void swap(int *arr, int i, int j) {
//    int temp = arr[i];
//    arr[i] = arr[j];
//    arr[j] = temp;
//}
//
//// 调整索引为idx的元素在[idx,end]区间 符合最大堆的性质
//void shiftDown(int *arr, int idx, int end){
//    int temp = arr[idx];
//    while (idx * 2 + 1 <= end) {
//        int j = idx * 2 + 1;
//        if (j + 1 <= end && arr[j + 1] > arr[j]) {
//            j = j + 1;
//        }
//        if (temp >= arr[j]) {
//            break;
//        }
//        arr[idx] = arr[j];
//        idx = j;
//    }
//    arr[idx] = temp;
//}
//
//
//// 原地堆排序
//int *heapSort(int *arr, int n){
//    // heapfiy:将数组堆化
//    for (int i = (n - 2) / 2; i >= 0; --i) {
//        shiftDown(arr, i, n - 1);
//    }
//
//    for (int j = N - 1; j > 0; --j) {
//        swap(arr, 0, j);
//        shiftDown(arr, 0, j - 1);
//    }
//    return arr;
//}
//
//int main(void){
//    int *arr = (int *) malloc(sizeof(int) * N);
//    for (int i = 0; i < N; ++i) {
//        arr[i] = (int) (rand() % 100);
//    }
//    printf("HeapSort Before:\n");
//    for (int i = 0; i < N; ++i) {
//        if(i%10==0){
//            printf("\n");
//        }
//        printf("%d\t", arr[i]);
//    }
//    printf("\nHeapSort After:\n");
//    arr = heapSort(arr, N);
//    for (int i = 0; i < N; ++i) {
//        if(i%10==0){
//            printf("\n");
//        }
//        printf("%d\t", arr[i]);
//    }
//    free(arr);
//    return 0;
//}