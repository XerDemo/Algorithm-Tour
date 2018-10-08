#include "ListHelper.h"

// 时间复杂度O(max(m,n))   空间复杂度O(1)      m:l1.length  n:l2.length
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // 建头结点  不需要另外创建链表存放答案
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = l1;
    struct ListNode *curNode_1 = l1, *curNode_2 = l2,*tail = dummy;
    // l1和l2当前节点都不为NULL
    while (curNode_1 != NULL && curNode_2!= NULL) {
        if (curNode_1->val <= curNode_2->val) {
            tail->next = curNode_1;
            tail = curNode_1;
            curNode_1 = curNode_1->next;
        } else{
            tail->next = curNode_2;
            tail = curNode_2;
            curNode_2 = curNode_2->next;
        }
    }
    if (curNode_1 != NULL) {
        tail->next = curNode_1;
    }
    if (curNode_2 != NULL) {
        tail->next = curNode_2;
    }
    return dummy->next;
}

int main(void) {
    int list_1[3] = {1, 2, 4};
    int list_2[2] = {2, 3};
    struct ListNode *head_1 = createList(list_1, 3);
    struct ListNode *head_2 = createList(list_2, 2);
    printList(mergeTwoLists(head_1, head_2));
    return 0;
}