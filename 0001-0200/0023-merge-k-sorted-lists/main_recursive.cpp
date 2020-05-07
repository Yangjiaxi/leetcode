/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  private:
    ListNode *merge2(ListNode *a, ListNode *b) {
        if (!a || !b)
            return a ? a : b;
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }

    ListNode *mergeN(vector<ListNode *> &lists, int l, int r) {
        // Merge lists whose indices in [l, r]
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int mid = l + ((r - l) >> 1);
        return merge2(mergeN(lists, l, mid), mergeN(lists, mid + 1, r));
    }

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) { return mergeN(lists, 0, lists.size() - 1); }
};