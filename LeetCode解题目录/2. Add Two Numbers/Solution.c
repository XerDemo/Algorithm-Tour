#include "ListHelper.h"

// 时间复杂度O(max(n, m)) n:l1.length m:l2.length  空间复杂度O(max(m,n))
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    // 创建一个带头结点dummy的链表来存放结果
    LinkNode *dummy = (LinkNode *) malloc(sizeof(LinkNode));
    int sum = 0, carry = 0;
    LinkNode *curNode_1 = l1, *curNode_2 = l2, *newNode = NULL, *tail = NULL;
    tail = dummy;
    tail->next = NULL;
    // 遍历l1和l2 ,curNode_1是l1当前所在节点 ,l2同理;
    while (curNode_1 && curNode_2){
        sum = curNode_1->val + curNode_2->val + carry;  // 当前对应两节点的值 + 进位
        carry = sum / 10;
        // 创建新的节点来存放sum % 10 如果是12则只保留2 carry = 1,并将此节点挂到tail的指针域并更新tail的位置
        newNode = (LinkNode *) malloc(sizeof(LinkNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        // 更新curNode_1和curNode_2的位置
        curNode_1 = curNode_1->next;
        curNode_2 = curNode_2->next;
    }

    // 如果l2已经空了
    while (curNode_1){
        sum = curNode_1->val + carry;
        newNode = (LinkNode *) malloc(sizeof(LinkNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        carry = sum / 10;
        tail->next = newNode;
        tail = newNode;
        curNode_1 = curNode_1->next;
    }
    // 如果l1已经空了
    while (curNode_2){
        sum = curNode_2->val + carry;
        newNode = (LinkNode *) malloc(sizeof(LinkNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        carry = sum / 10;
        tail->next = newNode;
        tail = newNode;
        curNode_2 = curNode_2->next;
    }
    // 两个链表最后两节点相加时>=10 创建一个节点保存进位
    if (carry > 0){
        newNode = (LinkNode *) malloc(sizeof(LinkNode));
        newNode->val = carry;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return dummy->next;
}

int main(void) {
    int list_1[2] = {1,8};
    int list_2[1] = {0};
    LinkNode *head_1 = createList(list_1, 2);
    LinkNode *head_2 = createList(list_2, 1);
    printList(head_1);
    printList(head_2);
    printList(addTwoNumbers(head_1, head_2));
    return 0;
}