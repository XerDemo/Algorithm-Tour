//
//#include<stdio.h>
//#include <stdlib.h>
//
//typedef struct node{
//    int data;
//    struct node * next;
//}LinkedNode;
//
//LinkedNode * create(){
//    LinkedNode *head = (LinkedNode *) malloc(sizeof(LinkedNode));
//    head->data = 1;
//    head->next = NULL;
//
//    LinkedNode * sec = (LinkedNode *) malloc(sizeof(LinkedNode));
//    sec->data = 2;
//    sec->next = NULL;
//    head->next = sec;
//    printf("head");
//    free(sec);
//    sec = NULL;
//    printf("%x\n", head->next);
//    return head;
//}
//
//int main()
//{
//    LinkedNode *head = create();
//    printf("%x\n", head);
//    return 0;
//}