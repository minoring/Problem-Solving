#define NULL 0

struct ListNode {
   int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res_list = new ListNode((l1->val + l2->val) % 10);
        int carry = (l1->val + l2->val) / 10;
        ListNode* rear = res_list;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != NULL && l2 != NULL) {
            rear->next = new ListNode((carry + l1->val + l2->val) % 10);
            carry = (carry + l1->val + l2->val) / 10;
            l1 = l1->next;
            l2 = l2->next;
            rear = rear->next;
        }

        while (l1 != NULL) {
            rear->next = new ListNode((carry + l1->val) % 10);
            carry = (carry + l1->val) / 10;
            l1 = l1->next;
            rear = rear->next;
        }

        while (l2 != NULL) {
            rear->next = new ListNode((carry + l2->val) % 10);
            carry = (carry + l2->val) / 10;
            l2 = l2->next;
            rear = rear->next;
        }

        if (carry == 1) {
            rear->next = new ListNode((1));
        }

        return res_list;
    }
};