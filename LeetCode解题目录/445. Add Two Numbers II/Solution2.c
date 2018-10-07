#include "ListHelper.h"
#include "LinkStackHelper.h"


// 时间复杂度O(N)
// 改进 1. 不需要利用stack_sum 直接使用从头部插入节点的建立链表方式
//      2. 将两个栈空 一个栈空  最后两个数进位为1 等情况整合起来
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    LinkStack *stack_1 = createStack();             // 此栈存放 l1链表
    LinkStack *stack_2 = createStack();             // 此栈存放 l2链表
    // 建虚拟头结点 指针域记得置NULL
    struct ListNode *dummy = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode *curNode_1 = l1, *curNode_2 = l2, *pTail = dummy;
    // 将l1中所有节点 入栈 7 2 4 3 入栈变成 3 4 2 7
    while (curNode_1) {
        push(stack_1, curNode_1->val);
        curNode_1 = curNode_1->next;
    }
    // 将l2中所有节点 入栈
    while (curNode_2) {
        push(stack_2, curNode_2->val);
        curNode_2 = curNode_2->next;
    }

    int sum = 0, carry = 0;
    // 改进： 将两个栈空 一个栈空  最后两个数进位为1 等情况整合起来
    while (!emptyStack(stack_1) || !emptyStack(stack_2) || carry != 0) {
        int val_1 = emptyStack(stack_1) ? 0 : pop(stack_1);
        int val_2 = emptyStack(stack_2) ? 0 : pop(stack_2);
        sum = val_1 + val_2 + carry;
        carry = sum / 10;
        struct ListNode *pNew = (struct ListNode *) malloc(sizeof(struct ListNode));
        pNew->val = sum % 10;
        pNew->next = dummy->next;
        dummy->next = pNew;
    }
    return dummy->next;
}

int main(void) {
    int list_1[4] = {7, 2, 4, 3};
    int list_2[3] = {5, 6, 4};
    struct ListNode *head_1 = createList(list_1, 4);
    struct ListNode *head_2 = createList(list_2, 3);
    struct ListNode *newHead = addTwoNumbers(head_1, head_2);
    printList(newHead);
    return 0;
}