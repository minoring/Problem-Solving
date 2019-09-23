/*
https://leetcode.com/problems/palindrome-linked-list/
Approach: Find middle of linked list using fast and slow pointer
Reverse Linked list in the middle, and compare if it is palindrome
Tip: 뒤집어서 비교한다는걸 생각은 했는데 실제로 할 생각은 잘 안했을듯.
근데 Linked list는 단방향이라서 뒤집는것밖에 없다.
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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow != nullptr) {
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next;

        while (head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};