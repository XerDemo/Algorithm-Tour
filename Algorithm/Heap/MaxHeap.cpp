//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXSIZE 100   // 堆的容量 可以用动态数组来扩充
//#define N 20 // 数组容量
//
//// 最大堆的定义
//typedef struct {
//    int data[MAXSIZE];
//    int size;         // 堆中元素个数
//} MaxHeap;
//
//MaxHeap *buildHeap(int *arr, int n);  // 建堆
//void insert(MaxHeap *heap, int val);   // 插入元素
//void shiftUp(MaxHeap *heap, int idx);  // 上浮
//int entractMax(MaxHeap *heap);         // 取出最大堆堆顶元素 并删除
//void shiftDown(MaxHeap *heap, int idx); // 下浮
//void swap(int *data, int i, int j);
//
//// heapify:将任意数组整理成堆的形状 将每个节点都符合最大堆的性质
////         因为叶节点本身没有子节点所以符合最大堆的性质，只需从最后一个非叶子节点到堆顶节点，依次将每个节点堆化
//// 注意：heapfiy之后数组中元素并不是从大到小的顺序
//MaxHeap *buildHeap(int *arr, int n) {
//    // 初始化堆 并且 对堆进行赋值
//    /*** 堆中元素 ∈ [0,size-1] ***/
//    MaxHeap *heap = (MaxHeap *) malloc(sizeof(MaxHeap));
//    heap->size = 0;
//    for (int i = 0; i < n; ++i) {
//        heap->data[i] = arr[i];
//        heap->size++;
//    }
//    //  heapfiy:最后一个节点的索引为size-1，因为数组从0开始，所以最后一个非叶子节点索引(size-1-1)/2
//    for (int i = (heap->size - 2) / 2; i >= 0; --i) {
//        shiftDown(heap, i);
//    }
//    printf("size:%d\n\n", heap->size);
//    return heap;
//}
//
//// 向堆中插入元素 时间复杂度O(logN)
//void insert(MaxHeap *heap, int val) {
//    if (heap->size - 1 == MAXSIZE - 1) { // 堆满  堆中元素存放在[0,size-1]
//        printf("堆中元素已满!可以用动态数组扩充.\n");
//        return;
//    }
//    heap->data[heap->size] = val;
//    heap->size++; // 更新size
//    shiftUp(heap, heap->size - 1); // 将新插入的元素，放在堆中适当的位置，满足最大堆的性质
//}
//
//// 上浮操作 时间复杂度O(logN)
//// 将待调整节点与其父节点比较，如果待调整节点比其父节点大，交换两者位置
//// 待调整节点继续与其新父节点比较，如果遇到待调整节点 <= 父亲节点，结束，否则一直执行此过程
//void shiftUp(MaxHeap *heap, int idx) {
////    // idx >= 1 代码上讲防止了数组越界
////    // 实际意义：idx=0是堆顶元素 其子节点idx要么是1(左孩子)要么是2(右孩子),在idx=2或1的时候已经和堆顶元素进行了比较
////    while (idx >= 1 && heap->data[idx] > heap->data[(idx - 1) / 2]) { // 待调整节点比其父节点大，交换两者位置
////        swap(heap->data, idx, (idx - 1) / 2);
////        idx = (idx - 1) / 2; // 更新待调整节点 在堆中的位置
////    }
//
//    // 优化：减少赋值次数 交换时需要3次赋值，执行一次swap，赋值3^n
//    int temp = heap->data[idx];
//    while (idx >= 1 && temp > heap->data[(idx - 1) / 2]) { // 待调整节点比其父节点大，交换两者位置
//        heap->data[idx] = heap->data[(idx - 1) / 2];
//        idx = (idx - 1) / 2; // 更新待调整节点 在堆中的位置
//    }
//    heap->data[idx] = temp;
//}
//
//// 向最大堆中取出堆顶元素 即堆中的最大元素 O(logN)
//// 基本思想：将最后一个元素与堆顶元素互换，此时新的堆顶元素不一定符合最大堆的性质，对其进行shiftDown
//int entractMax(MaxHeap *heap) {
//    if (heap->size <= 0) {
//        printf("堆中没有元素.\n");
//        return -1;
//    }
//    int max = heap->data[0];   // 堆顶元素
////	printf("出堆元素: %d \n", max);
//    swap(heap->data, 0, heap->size - 1); // 将堆顶元素与堆中最后一个元素互换  堆中元素存在[0,size-1]中，起到了删除堆顶元素的作用
//    heap->size--;  // 更新size
//    shiftDown(heap, 0);  // 让调整新的堆顶元素 使其符合最大堆性质
//    return max;
//}
//
//// 下沉操作 调整索引为idx的节点，使其符合最大堆性质
//// 基本思想：将当前元素与自己的左右孩子中最大的那个比较，如果比最大的孩子小，交换两者位置
//// 继续与新的左右孩子比较，直到大于等于左右孩子中最大的，此时符合最大堆的性质
//void shiftDown(MaxHeap *heap, int idx) {
////    while (idx * 2 + 1 <= heap->size - 1) { // 左孩子 = idx *2 +1 如果在堆中  [0,size-1]
//////        int j = idx * 2 + 1;
//////        // 如果有右孩子 并且右孩子比左孩子大
//////        if (j + 1 <= heap->size - 1 && heap->data[j + 1] > heap->data[j]) {
//////            j = j + 1; // 更新j为右孩子的索引
//////        }
//////        if (heap->data[idx] >= heap->data[j]) { //  待调节点 >= 左右孩子最大
//////            break; // 满足最大堆性质 结束
//////        }
//////        swap(heap->data, idx, j); // 交换待调节点与其左右孩子最大的
//////        idx = j; // 更新待调节点为 左右孩子最大的
//////    }
//
//    // 优化：减少赋值次数 交换时需要3次赋值，执行一次swap，赋值3^n
//    int temp = heap->data[idx];
//    while (idx * 2 + 1 <= heap->size - 1) { // 左孩子 = idx *2 +1 如果在堆中  [0,size-1]
//        int j = idx * 2 + 1;
//        // 如果有右孩子 并且右孩子比左孩子大
//        if (j + 1 <= heap->size - 1 && heap->data[j + 1] > heap->data[j]) {
//            j = j + 1; // 更新j为右孩子的索引
//        }
//        if (temp >= heap->data[j]) { //  待调节点 >= 左右孩子最大
//            break; // 满足最大堆性质 结束
//        }
//        heap->data[idx] = heap->data[j];
//        idx = j; // 更新待调节点为 左右孩子最大的
//    }
//    heap->data[idx] = temp;
//}
//
//// 获取最大堆顶元素 即整个堆中最大的元素
//int getHeadTop(MaxHeap *heap) {
//    if (heap->size <= 0) {
//        printf("堆中没有元素.");
//        return -9999999;
//    }
//    return heap->data[0];
//}
//
//// 取出堆中的最大元素，并且替换成元素e
//int replace(MaxHeap *heap, int e) {
//    int max = heap->data[0]; // 堆中最大元素
//    heap->data[0] = e; // 修改堆顶元素
//    shiftDown(heap, 0); // 修改后堆顶元素不一定满足最大堆性质
//    return max;
//}
//
//
//// 交换
//void swap(int *data, int i, int j) {
//    int temp = data[i];
//    data[i] = data[j];
//    data[j] = temp;
//}
//
//
//int main(void) {
//    int arr[N] = {0};
//    for (int i = 0; i < N; ++i) {
//        arr[i] = (int) (rand() % 50);
//    }
//    for (int i = 0; i < N; ++i) {
//        printf("%d  ", arr[i]);
//    }
//    MaxHeap *heap = buildHeap(arr, N);
//
//    for (int i = 0; i < 5; ++i) {
//        insert(heap, i % 2 == 0 ? i * 10 : -i * 10);
//    }
//    printf("添加元素后的堆 size:%d\n", heap->size);
//
//    int len = heap->size;
//    printf("看堆顶元素 但是不取出来\n");
//    printf("top:%d \n", getHeadTop(heap));
//    replace(heap, -9999); // 修改堆顶
//
//    for (int i = 0; i < len; ++i) {
//        printf("\ntop:%d ", entractMax(heap));
//        printf("\t\tsize:%d", heap->size);
//    }
//
//}
//
