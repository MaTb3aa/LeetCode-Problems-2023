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
  

ListNode* mergeKLists(vector<ListNode*>& lists) {
     // Define a lambda function to use as the comparator for the min-heap
    auto cmp = [](const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    };
    
    // Create a min-heap of size k, where k is the number of linked lists
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (ListNode* node : lists) {
        if (node) pq.push(node);
    }
    
    // Create a dummy head node and a tail pointer for the result list
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    
    // Extract the minimum element from the heap, add it to the result list,
    // and insert the next element from the same linked list into the heap
    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        tail->next = node;
        tail = node;
        if (node->next) pq.push(node->next);
    }
    
    // Free the dummy head node and return the result list
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}
};