/*
https://leetcode.com/problems/reverse-linked-list/
Approach: Recursive
Algorithm:
Recursive through all linked list and connect to previous node.
Time Complexity: O(n)
Space Complexity: O(n). call stack of recursion
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        head = reverseListHelper(head, nullptr);
        return head;
    }

    ListNode* reverseListHelper(ListNode* curr, ListNode* prev) {
        if (curr == nullptr) {
            return prev;
        }
        ListNode* head = reverseListHelper(curr->next, curr);
        curr->next = prev;
        return head;
    }
};