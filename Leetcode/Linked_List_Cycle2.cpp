class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        while (head != slow) {
          head = head->next;
          slow = slow->next;
        }
        return head;
      }
    }
    return nullptr;
  }
};
