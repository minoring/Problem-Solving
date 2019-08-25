struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        ListNode** curr = &head;
        ListNode* a;
        ListNode* b;

        while ((a = *curr) && (b = (*curr)->next)) {
            a->next = b->next;
            b->next = a;
            *curr = b;
            curr = &(a->next);
        }
        return head;
    }
};

/*
https://leetcode.com/problems/swap-nodes-in-pairs/
Approach: Linked List
Basic concept of linked list.
I have to start with small and specific example.
*/ 