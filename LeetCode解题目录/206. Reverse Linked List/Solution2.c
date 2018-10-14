#include "ListHelper.h"


// 时间复杂度O(N)  空间复杂度O(1)  头插法(栈)
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *dummyHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummyHead->next = NULL;

    struct ListNode  *curNode = head, *nextNode = NULL ;
    while (curNode != NULL) {
        nextNode = curNode->next;
        curNode->next = dummyHead->next;
        dummyHead->next = curNode;
        curNode = nextNode;
    }
    return dummyHead->next;
}

int main(void) {
    int list[5] = {1, 3, 3, 3, 5};
    struct ListNode *head = createList(list, 5);
    printList(reverseList(head));
    return 0;
}