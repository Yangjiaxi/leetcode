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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2)
            return nullptr;

        ListNode *res = nullptr, *head;
        if (!l1) {
            head = res = l2;
            l2 = l2->next;
        } else if (!l2) {
            head = res = l1;
            l1 = l1->next;
        } else {
            if (l1->val <= l2->val) {
                head = res = l1;
                l1 = l1->next;
            } else {
                head = res = l2;
                l2 = l2->next;
            }
            while (l1 && l2) {
                if (l1->val <= l2->val) {
                    res->next = l1;
                    res = l1;
                    l1 = l1->next;
                } else {
                    res->next = l2;
                    res = l2;
                    l2 = l2->next;
                }
            }
        }

        if (l1)
            res->next = l1;
        if (l2)
            res->next = l2;

        return head;
    }
};