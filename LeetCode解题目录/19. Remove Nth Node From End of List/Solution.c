#include <stdio.h>
#include <stdlib.h>
#include "ListHelper.h"

// 时间复杂度O(n)  空间O(1)
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL || n <= 0) {
        return head;
    }
    struct ListNode * dummyHead = (struct ListNode *) malloc (sizeof(struct ListNode));
    dummyHead->next = head;

    int i = 0;
    struct ListNode * p = dummyHead, *q = dummyHead, *pre = dummyHead;
    // 找到q的位置
    while (i < n && q) {
        q = q->next;
        i++;
    }
    // q不空p、q同时后移 pre是p的前驱
    while (q != NULL) {
        pre = p;
        p = p->next;
        q = q->next;
    }

    pre->next = p->next;
    free(p);
    p = NULL;
    return dummyHead->next;
}

int main(void) {
    int listA[5] = {1, 2, 3, 4, 5};
    int n = 2;
    LinkNode *headA = createList(listA, 5);
    printList(removeNthFromEnd(headA, n));
    return 0;
}
