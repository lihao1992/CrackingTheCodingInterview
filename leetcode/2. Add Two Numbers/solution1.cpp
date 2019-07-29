#include <iostream>


/* Definition for singly-linked list. */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        // set a carry bit
        int carry = 0;
        // 判断链表是否为空，以及取出当前元素
        while(l1 || l2 || carry){
            // 如果最后只剩最高位进位，则只加进位项
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            // 如果有进位，保留进位
            carry = sum / 10;
            // 取余存入链表中
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return head->next;
    }
};