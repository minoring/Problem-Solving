struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* cur_node = dummy_head;

        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                cur_node->next = new ListNode(l2->val);
                l2 = l2->next;
            } else if (l2 == nullptr) {
                cur_node->next = new ListNode(l1->val);
                l1 = l1->next; 
            } else {
                if (l1->val < l2->val) {
                    cur_node->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    cur_node->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            }
            cur_node = cur_node->next;
        }

        return dummy_head->next;
    }
};