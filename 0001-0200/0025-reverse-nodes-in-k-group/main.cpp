#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using T = ListNode *;

class Solution {
  public:
    T reverseKGroup(T head, int k) {
        if (head == nullptr || k == 1)
            return head;

        T guard = new ListNode();
        guard->next = head;

        T curr = head;
        T pre = guard;
        T tail = nullptr;
        T next = nullptr;

        while (curr) {
            tail = stepK(curr, k - 1);
            if (!tail)
                break; // inefficient nodes

            next = tail->next;

            tie(curr, tail) = flip(curr, tail);

            pre->next = curr;
            tail->next = next;

            pre = tail;
            curr = tail->next;
        }
        return guard->next;
    }

    pair<T, T> flip(T begin, T end) {
        T curr = begin, prev = end->next, next = nullptr;
        while (prev != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {end, begin};
    }

    T stepK(T begin, int k) {
        T curr = begin;
        for (int i = 0; i < k; ++i) {
            if (curr->next)
                curr = curr->next;
            else
                return nullptr;
        }
        return curr;
    }

    void static print(T begin, T end = nullptr) {
        T curr = begin;
        end = end == nullptr ? nullptr : end->next;
        while (curr != end) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

T cr(int v, T next = nullptr) { return new ListNode(v, next); }

int main() {
    Solution a;

    T head = cr(1, cr(2, cr(3, cr(4, cr(5)))));

    Solution::print(head);
    head = a.reverseKGroup(head, 2);
    Solution::print(head);

    return 0;
}