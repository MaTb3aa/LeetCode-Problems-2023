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
    struct Compare {
    bool operator() (const ListNode* a, const ListNode* b) const {
        return a->val < b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<ListNode*, Compare> s;
        for (auto head : lists) {
            while (head) {
                s.insert(head);
                head = head->next;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for (auto node : s) {
            tail->next = node;
            tail = node;
        }
        return dummy->next;
    }
};