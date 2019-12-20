//#include <stdio.h>
//#include <stdlib.h>
//#define INITSIZE 10 // �����ʼ����
//#define E int
//
///*
//// ��̬����ڵ㶨��
//typedef struct {
//    E data[INITSIZE];  // ���鳤��Ϊ�̶�����
//    int size;
//}Array;
//*/
//
//// ��̬����ڵ㶨��
//typedef struct {
//    E * data;      // ��̬��������Ŀռ��ַ
//    int capacity;  // ������������
//    int size;      // ����Ԫ�ص�ǰ��ռ���� size:0 ��ʾ�����
//                   // �еĽ̲���int lastָ���������һ��Ԫ�ص��±�  ��ʼʱΪ�գ�last = -1 ����ԭ��һ��
//}Array;
//
//
//// ��ʼ����̬����
//Array * initArray(){
//    Array *arr = (Array *) malloc(sizeof(Array));
//    arr->data = (E *) malloc(sizeof(E) * INITSIZE);
//    arr->capacity = INITSIZE;
//    arr->size = 0;
//}
//
//// ��ȡ���������   O(1)
//int getCapacity(Array * arr){
//    return arr->capacity;
//}
//
//// ��ȡ�����е�Ԫ�ظ���  O(1)
//int getSize(Array * arr){
//    return arr->size;
//}
//
//// ���������Ƿ�Ϊ�� O(1)
//int isEmpty(Array * arr){
//    return arr->size;
//}
//
//// ������ռ���������ݳ�newCapacity��С O(N)
//void resize(Array * arr,int newCapacity){
//    E *newDate = (E *) malloc(sizeof(E) * newCapacity); // �˴�����ʹ��realloc
//    int i;
//    for (i = 0; i < arr->size; ++i) {
//        newDate[i] = arr->data[i];
//    }
//    arr->data = newDate;
//    arr->capacity = newCapacity;
//}
//
//// ��index������λ�ò���һ����Ԫ��e   index��[0,size]  O(N)
//void add(Array * arr,int index, E e){
//    if (index < 0 || index > arr->size) { // indexλ�ò��Ϸ�
//        printf("Add failed. Require index [0,size].");
//        return;
//    }
//    if (arr->size == arr->capacity){ // ������ ��̬��������
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
//// ������Ԫ�غ����һ����Ԫ��   O(1)
//void addLast(Array * arr,E e){
//    add(arr, arr->size, e);
//}
//
//// ������Ԫ��ǰ���һ����Ԫ��   O(N)
//void addFirst(Array * arr,E e){
//    add(arr, 0, e);
//}
//
//// ��ȡindex����λ�õ�Ԫ�� O(1)
//E get(Array * arr,int index){
//    if (index < 0 || index >= arr->size) {
//        printf("Get failed. Index �� [0,size).");
//        return -9999999;
//    }
//    return arr->data[index];
//}
//
//// �޸�index����λ�õ�Ԫ��Ϊe O(1)
//void set(Array * arr,int index, E e){
//    if (index < 0 || index > arr->size) { // index��[0,size)
//        printf("Set failed. Index �� [0,size).");
//        return;
//    }
//    arr->data[index] = e;
//}
//
//// �����������Ƿ���Ԫ��e  O(N)
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
//// ����������Ԫ��e���ڵ����������������Ԫ��e���򷵻�-1  O(N)
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
//// ��������ɾ��indexλ�õ�Ԫ��, ����ɾ����Ԫ��   O(N)
//E Remove(Array * arr,int index){
//    if (index < 0 || index >= arr->size) { // index ��[0,size)
//        printf("Remove failed. Index �� [0,size).");
//        return -9999999;
//    }
//    E res = arr->data[index];
//    int i;
//    for (i = index + 1; i < arr->size; ++i) {
//        arr->data[i-1] = arr->data[i];
//    }
//    arr->size--;
//    // ��̬�������� ���õ�д����arr->size == arr->capacity / 4 && arr->capacity / 2 !=0
//    if (arr->size == arr->capacity / 2) {
//        resize(arr, arr->capacity / 2);
//    }
//    return res;
//}
//
//// ��������ɾ����һ��Ԫ��, ����ɾ����Ԫ��   O(N)
//E removeFirst(Array * arr){
//    return Remove(arr, 0);
//}
//
//// ��������ɾ�����һ��Ԫ��, ����ɾ����Ԫ��  O(1)
//E removeLast(Array * arr){
//    return Remove(arr, arr->size - 1);
//}
//
//// ��������ɾ��Ԫ��e   O(N)
//void removeElement(Array * arr,E e){
//    int index = find(arr, e);
//    if (index != -1) {
//        Remove(arr, index);
//    }
//}
//
//// ��ӡ������Ϣ
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
// *  ��������ʵ�ֵ�ջ�Ͷ��ж��� ����������Ӽ�
// *  ջ(����)��addLast() ��ջ O(1); removeLast() ��ջ O(1); get(index:size-1)��ջ��Ԫ��O(1)
// *  ����(����)��addLast() ��� O(1); removeFirst() ���� o(N) ; get(index:0) ����ͷԪ�� O(1)��get(index:size-1) �ȶ�βԪ��O(1)
// *           ��Ϊ������O(N) ���Ǽ����βָ�벢���ж�Ӧ�ĸı� ʹ���ӱ��O(1)
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
