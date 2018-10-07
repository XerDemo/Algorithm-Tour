#include "ListHelper.h"
#include "LinkStackHelper.h"


// 时间复杂度O(N)
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    LinkStack *stack_1 = createStack();             // 此栈存放 l1链表
    LinkStack *stack_2 = createStack();             // 此栈存放 l2链表
    LinkStack *stack_sum = createStack();           // 此栈存放结果
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
    // 两个栈都不为空 则将其栈顶元素 + 进位 入stack_sum栈
    while (!emptyStack(stack_1) && !emptyStack(stack_2)) {
        sum = pop(stack_1) + pop(stack_2) + carry;
        carry = sum / 10;
        push(stack_sum, sum % 10);
    }
    // 如果stack_1不空  stack_2空
    while (!emptyStack(stack_1)) {
        sum = pop(stack_1) + carry;
        carry = sum / 10;
        push(stack_sum, sum % 10);
    }
    // 如果stack_2不空  stack_1空
    while (!emptyStack(stack_2)) {
        sum = pop(stack_2) + carry;
        carry = sum / 10;
        push(stack_sum, sum % 10);
    }
    // 当遍历到最后两个数 相加时 其值 >= 10
    if (carry > 0) {
        push(stack_sum, carry);
    }
    // 将stack_sum中的元素出栈 加入到链表dummy中 从 7 0 8 7变成 7 8 0 7
    while (!emptyStack(stack_sum)){
        struct ListNode *pNew = (struct ListNode *) malloc(sizeof(struct ListNode));
        pNew->val = pop(stack_sum);
        pNew->next = NULL;
        pTail->next = pNew;
        pTail = pNew;
    }
    return dummy->next;
}

int main(void) {
    int list_1[4] = {7, 2, 4, 3};
    int list_2[3] = {5, 6, 4};
    struct ListNode *head_1 = createList(list_1, 4);
    struct ListNode *head_2 = createList(list_2, 3);
    struct ListNode *newHead =  addTwoNumbers(head_1, head_2);
    printList(newHead);
    return 0;
}