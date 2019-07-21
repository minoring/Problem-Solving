#define NULL 0

struct ListNode {
   int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* dummy = new ListNode(0);
        int carry = 0;
        ListNode* rear = dummy;

        while (p != NULL || q != NULL) {
            int p_val = (p != NULL) ? p->val : 0;
            int q_val = (q != NULL) ? q->val : 0;
            rear->next = new ListNode((carry + p_val + q_val) % 10);
            carry = (carry + p_val + q_val) / 10;

            if (p != NULL)
                p = p->next;
            if (q != NULL)
                q = q->next;
            rear = rear->next;
        }

        if (carry > 0) {
            rear->next = new ListNode((1));
        }

        return dummy->next;
    }
};