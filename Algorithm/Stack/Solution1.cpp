//#include "ArrayStack.h"
//#include <string.h>
///**
// * 车厢调度
// * 思想：
// * @param train
// * @return
// */
//char *solution(char * train){
//    char * res = train;
//    int len = strlen(train);
//    int j = 0;
//    ArrayStack *stack = initStack();
//    for (int i = 0; i < len; ++i) {
//        if (train[i] == 'H'){
//            push(stack, train[i]);
//        }else{
//            res[j++] = train[i];
//        }
//    }
//
//    while (!isEmpty(stack)) {
//        res[j++] = pop(stack);
//    }
//    return res;
//}
//
//int main(void){
//    char train[10] = "HHSHSSHHS";
//    puts(solution(train));
//    return 0;
//}