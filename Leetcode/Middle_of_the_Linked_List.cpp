/*
Two pointers.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* a = head;
        ListNode* b = head;
        while (b != NULL) {
            b = b->next;
            if (b == NULL) {
                return a;
            }
            a = a -> next;
            b = b -> next;
        }
        return a;
    }
};