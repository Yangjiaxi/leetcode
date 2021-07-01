#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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

using T = ListNode *;

class Solution {
  public:
    pair<T, T> flip(T begin, T end) {
        T prev = end->next;
        T curr = begin;
        T next = nullptr;
        while (prev != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {end, begin};
    }

    T stepK(T begin, int k) {
        if (k == 0)
            return begin;
        if (k < 0)
            return nullptr;
        T curr = begin;
        for (int i = 0; i < k; ++i)
            curr = curr->next;
        return curr;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right) {
        T pre = stepK(head, left - 2);
        T begin = pre ? pre->next : head;
        T end = stepK(begin, right - left);

        tie(begin, end) = flip(begin, end);

        if (pre) {
            pre->next = begin;
            return head;
        } else {
            return begin;
        }
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
    head = a.reverseBetween(head, 3, 4);
    Solution::print(head);

    return 0;
}