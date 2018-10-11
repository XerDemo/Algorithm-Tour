#include "ListHelper.h"

// 时间复杂度O(N)   空间复杂度O(1)
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *dummyHead = (struct ListNode *) malloc(sizeof(struct ListNode));
    dummyHead->next = head;
    struct ListNode *pre = dummyHead, *curNode = NULL,*pCount =NULL, *nextNode = NULL;
    while (1){
        int i = 0;
        pCount = pre;          // pCount只是用来遍历从pre开始往后数满不满足K个而已
        while (i< k && pCount!=NULL){
            pCount = pCount->next;
            i++;
        }
        if (NULL == pCount){  // 遍历到链表尾了
            break;
        }
        curNode = pre->next;  // 找到curNode的位置
        for (i = 0; i < k - 1 && curNode != NULL; ++i) {    // 开始翻转
            nextNode = curNode->next;
            curNode->next = nextNode->next;
            nextNode->next = pre->next;
            pre->next = nextNode;
        }
        pre = curNode;              // 更新pre的位置
    }
    return dummyHead->next;
}

int main(void) {
    int list[5] = {1, 2, 3, 4, 5};
    int k = 2;
    struct ListNode *head = createList(list, 5);
    printList(reverseKGroup(head,k));
    return 0;
}