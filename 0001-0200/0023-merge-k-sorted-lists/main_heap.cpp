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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        struct Inner {
            ListNode *p;
            int val;
            bool operator<(const Inner &rhs) const { return val > rhs.val; }
            Inner(int _val, ListNode *_p) : val(_val), p(_p) {}
        };

        priority_queue<Inner> Q;
        for (auto &head : lists)
            if (head)
                Q.emplace(head->val, head);

        ListNode dummy(-1);
        ListNode *tail = &dummy;

        while (!Q.empty()) {
            auto t = Q.top();
            Q.pop();
            tail->next = t.p;
            tail = tail->next;
            auto tt = t.p->next;
            if (tt)
                Q.emplace(tt->val, tt);
        }
        return dummy.next;
    }
};