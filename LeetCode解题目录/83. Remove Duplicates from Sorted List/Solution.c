#include "ListHelper.h"

// 时间复杂度O(N)  空间复杂度O(1)
struct ListNode *deleteDuplicates(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    LinkNode *curNode = head;                         // 当前所在点
    LinkNode *nextNode = head->next;                  // 当前节点的下一个节点
    while (curNode && nextNode){
        if (curNode->val == nextNode->val){           // 两者数据域相等
            curNode->next = nextNode->next;
            nextNode = nextNode->next;
        } else{
            curNode = nextNode;
            nextNode = nextNode->next;
        }
    }
    return head;
}

int main(void) {
    int list[5] = {1, 1, 2, 3, 3};
    LinkNode *head = createList(list, 5);
    printList(head);
    LinkNode *newHead = deleteDuplicates(head);
    printList(newHead);
}