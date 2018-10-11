#include "ListHelper.h"

// 时间复杂度O(max(n, m)) n:l1.length m:l2.length  空间复杂度O(max(m,n))
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    // 创建一个带头结点dummy的链表来存放结果
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    int sum = 0, carry = 0;
    struct ListNode *curNode_1 = l1, *curNode_2 = l2, *newNode = NULL, *tail = dummy;
    tail->next = NULL;

    // 将多种情况 合并在一起解决
    while (curNode_1 || curNode_2 || carry != 0) {
        int val_1 = curNode_1 == NULL ? 0 : curNode_1->val;
        int val_2 = curNode_2 == NULL ? 0 : curNode_2->val;
        sum = val_1 + val_2 + carry;            // 当前对应两节点的值 + 进位
        carry = sum / 10;

        // 创建新的节点来存放sum % 10 如果是12则只保留2 carry = 1,并将此节点挂到tail的指针域并更新tail的位置
        newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        // 更新curNode_1和curNode_2的位置
        if (curNode_1) {
            curNode_1 = curNode_1->next;
        }
        if (curNode_2) {
            curNode_2 = curNode_2->next;
        }
    }
    return dummy->next;
}

int main(void) {
    int list_1[2] = {1, 8};
    int list_2[1] = {0};
    struct ListNode *head_1 = createList(list_1, 2);
    struct ListNode *head_2 = createList(list_2, 1);
    printList(head_1);
    printList(head_2);
    printList(addTwoNumbers(head_1, head_2));
    return 0;
}