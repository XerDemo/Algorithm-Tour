#include "ListHelper.h"

// 时间复杂度O(max(m,n))   空间复杂度O(m+n)   m:l1.length  n:l2.length
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // 建头结点  新建一个链表来存放答案
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    // curNode_1：指向l1当前节点  curNode_2：指向l2当前节点   tail:指向新建链表dumm的最后一个节点
    struct ListNode *curNode_1 = l1, *curNode_2 = l2,*tail = dummy, *newNode = NULL;
    // l1和l2当前节点都不为NULL
    while (curNode_1 != NULL && curNode_2!= NULL) {
        newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        // 将curNode_1->val的值挂到dumm链表的最后一个节点上
        if (curNode_1->val <= curNode_2->val) {
            newNode->val = curNode_1->val;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
            curNode_1 = curNode_1->next;        // 更新curNode_1的位置
        } else{  // 将curNode_2->val的值挂到dumm链表的最后一个节点上
            newNode->val = curNode_2->val;
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
            curNode_2 = curNode_2->next;       // 更新curNode_2的位置
        }
    }
    // 如果l2空  将l1剩余节点直接挂到dumm的最后一个节点
    if (curNode_1 != NULL) {
        tail->next = curNode_1;
    }
    // 如果l1空  将l2剩余节点直接挂到dumm的最后一个节点
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