/*
https://leetcode.com/problems/intersection-of-two-linked-lists/
Approach: Two Pointer
Key: Moving each pointer to other head.
Longer Linked List travel exactly same different length than
shorter Linked List, so it will eventually be same length
if two nodes both reach the end and travel again.
Time Complexity: O(m + n)
Space Complexity: O(1)
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* ptr_a = headA;
        ListNode* ptr_b = headB;

        while (ptr_a != ptr_b) {
            ptr_a = ptr_a == nullptr ? headB : ptr_a->next;
            ptr_b = ptr_b == nullptr ? headA : ptr_b->next;
        }
        return ptr_a;
    }
};