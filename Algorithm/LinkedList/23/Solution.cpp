//#include "LinkedListHelper.h"
//#include <memory.h>
//
//int count[200];
//
//
//LinkNode *remove(LinkNode *head) {
//    if (head == NULL) {
//        return NULL;
//    }
//    memset(count, 0, sizeof(count));
//    LinkNode *p = head->next;
//    while (p != NULL) {
//        int k = abs(p->val);
//        count[k]++;
//        p = p->next;
//    }
//
//    p = head;
//    while (p != NULL && p->next != NULL) {
//        LinkNode *nextNode = p->next;
//        if (count[abs(nextNode->val)] > 1) {
//            p->next = nextNode->next;
//            --count[abs(nextNode->val)];
//            free(nextNode);
//            nextNode = NULL;
//        } else {
//            p = nextNode;
//        }
////        printf("888\n");
//    }
//
//    return head;
//}
//
//int main(void) {
//    int data1[5] = {21, -15, -15, -7, 15};
//    LinkNode *head = createLinkList_dummy(data1, 5);
//    printLinkList(head);
//
//    head = remove(head);
//    printf("\n\n");
//    printLinkList(head);
//    return 0;
//}