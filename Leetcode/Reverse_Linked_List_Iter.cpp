/*
https://leetcode.com/problems/reverse-linked-list/
Approach: Iteration
Algorithm:
Store previous node so that we can reverse linked list order.
Time Complexity: O(n)
Space Complexity: O(1)
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }
        return prev;
    }
};