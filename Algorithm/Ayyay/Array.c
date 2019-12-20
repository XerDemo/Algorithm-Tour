//#include <stdio.h>
//#include <stdlib.h>
//#define INITSIZE 10 // 数组初始容量
//#define E int
//
///*
//// 静态数组节点定义
//typedef struct {
//    E data[INITSIZE];  // 数组长度为固定长度
//    int size;
//}Array;
//*/
//
//// 动态数组节点定义
//typedef struct {
//    E * data;      // 动态分配数组的空间基址
//    int capacity;  // 数组的最大容量
//    int size;      // 数组元素当前所占容量 size:0 表示数组空
//                   // 有的教材是int last指向数组最后一个元素的下标  初始时为空：last = -1 两个原理一致
//}Array;
//
//
//// 初始化动态数组
//Array * initArray(){
//    Array *arr = (Array *) malloc(sizeof(Array));
//    arr->data = (E *) malloc(sizeof(E) * INITSIZE);
//    arr->capacity = INITSIZE;
//    arr->size = 0;
//}
//
//// 获取数组的容量   O(1)
//int getCapacity(Array * arr){
//    return arr->capacity;
//}
//
//// 获取数组中的元素个数  O(1)
//int getSize(Array * arr){
//    return arr->size;
//}
//
//// 返回数组是否为空 O(1)
//int isEmpty(Array * arr){
//    return arr->size;
//}
//
//// 将数组空间的容量扩容成newCapacity大小 O(N)
//void resize(Array * arr,int newCapacity){
//    E *newDate = (E *) malloc(sizeof(E) * newCapacity); // 此处可以使用realloc
//    int i;
//    for (i = 0; i < arr->size; ++i) {
//        newDate[i] = arr->data[i];
//    }
//    arr->data = newDate;
//    arr->capacity = newCapacity;
//}
//
//// 在index索引的位置插入一个新元素e   index∈[0,size]  O(N)
//void add(Array * arr,int index, E e){
//    if (index < 0 || index > arr->size) { // index位置不合法
//        printf("Add failed. Require index [0,size].");
//        return;
//    }
//    if (arr->size == arr->capacity){ // 数组满 动态增长数组
//        resize(arr, 2 * arr->capacity);
//    }
//    int i;
//    for (i = arr->size-1; i >=index ; --i) {
//        arr->data[i + 1] = arr->data[i];
//    }
//    arr->data[index] = e;
//    arr->size++;
//}
//
//// 向所有元素后添加一个新元素   O(1)
//void addLast(Array * arr,E e){
//    add(arr, arr->size, e);
//}
//
//// 在所有元素前添加一个新元素   O(N)
//void addFirst(Array * arr,E e){
//    add(arr, 0, e);
//}
//
//// 获取index索引位置的元素 O(1)
//E get(Array * arr,int index){
//    if (index < 0 || index >= arr->size) {
//        printf("Get failed. Index ∈ [0,size).");
//        return -9999999;
//    }
//    return arr->data[index];
//}
//
//// 修改index索引位置的元素为e O(1)
//void set(Array * arr,int index, E e){
//    if (index < 0 || index > arr->size) { // index∈[0,size)
//        printf("Set failed. Index ∈ [0,size).");
//        return;
//    }
//    arr->data[index] = e;
//}
//
//// 查找数组中是否有元素e  O(N)
//int contains(Array * arr,E e){
//    int i;
//    for (i = 0; i < arr->size; ++i) {
//        if (arr->data[i] == e) {
//            return 1;
//        }
//    }
//    return 0;
//}
//
//// 查找数组中元素e所在的索引，如果不存在元素e，则返回-1  O(N)
//int find(Array * arr,E e){
//    int i;
//    for (i = 0; i < arr->size; ++i) {
//        if (arr->data[i] == e) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//// 从数组中删除index位置的元素, 返回删除的元素   O(N)
//E Remove(Array * arr,int index){
//    if (index < 0 || index >= arr->size) { // index ∈[0,size)
//        printf("Remove failed. Index ∈ [0,size).");
//        return -9999999;
//    }
//    E res = arr->data[index];
//    int i;
//    for (i = index + 1; i < arr->size; ++i) {
//        arr->data[i-1] = arr->data[i];
//    }
//    arr->size--;
//    // 动态缩减数组 更好的写法：arr->size == arr->capacity / 4 && arr->capacity / 2 !=0
//    if (arr->size == arr->capacity / 2) {
//        resize(arr, arr->capacity / 2);
//    }
//    return res;
//}
//
//// 从数组中删除第一个元素, 返回删除的元素   O(N)
//E removeFirst(Array * arr){
//    return Remove(arr, 0);
//}
//
//// 从数组中删除最后一个元素, 返回删除的元素  O(1)
//E removeLast(Array * arr){
//    return Remove(arr, arr->size - 1);
//}
//
//// 从数组中删除元素e   O(N)
//void removeElement(Array * arr,E e){
//    int index = find(arr, e);
//    if (index != -1) {
//        Remove(arr, index);
//    }
//}
//
//// 打印数组信息
//void printMessage(Array * arr){
//    printf("Array:size = %d  , capacity = %d \n",arr->size,arr->capacity);
//    int i;
//    printf("[");
//    for (i = 0; i < arr->size; ++i) {
//        printf("%d", arr->data[i]);
//        if (i != arr->size - 1) {
//            printf(", ");
//        }
//    }
//    printf("]\n");
//}
//
///**
// *  基于数组实现的栈和队列都是 数组操作的子集
// *  栈(数组)：addLast() 入栈 O(1); removeLast() 出栈 O(1); get(index:size-1)读栈顶元素O(1)
// *  队列(数组)：addLast() 入队 O(1); removeFirst() 出队 o(N) ; get(index:0) 读队头元素 O(1)；get(index:size-1) 度队尾元素O(1)
// *           因为出队是O(N) 于是加入队尾指针并进行对应的改变 使出队变成O(1)
// */
//
//int main(void){
//    Array *arr = initArray();
//    Remove(arr,0);
//    printMessage(arr);
//    int i;
//    for (i = 0; i < 10; i++) {
//        addLast(arr, i);
//    }
//    printMessage(arr);
//
//    add(arr, 10, 999);
//    printMessage(arr);
//    removeFirst(arr);
//    printMessage(arr);
//    return 0;
//}
//
