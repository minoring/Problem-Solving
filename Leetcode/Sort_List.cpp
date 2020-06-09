/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *sortList(ListNode *head) { return mergeSort(head); }

  ListNode *mergeSort(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *mid = findMid(head);
    ListNode *sortedBack = mergeSort(mid->next);
    mid->next = nullptr;
    ListNode *sortedFront = mergeSort(head);

    return merge(sortedFront, sortedBack);
  }

  ListNode *merge(ListNode *l, ListNode *r) {
    if (l == nullptr || r == nullptr) {
      if (l == nullptr) {
        return r;
      }
      return l;
    }
    ListNode *sorted;

    if (l->val < r->val) {
      sorted = l;
      sorted->next = merge(l->next, r);
    } else {
      sorted = r;
      sorted->next = merge(l, r->next);
    }
    return sorted;
  }

  ListNode *findMid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr) {
      fast = fast->next;
      if (fast == nullptr || fast->next == nullptr) {
        return slow;
      }
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};
