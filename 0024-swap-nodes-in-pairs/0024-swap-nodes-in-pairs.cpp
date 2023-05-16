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
    ListNode* swapPairs(ListNode* head) {
    
        if(head==NULL || head->next==NULL)return head;
    
        ListNode* second = head->next;

        ListNode* first = head;

        swap(first->val,second->val);

        while(first->next->next!=NULL&&second->next->next!=NULL){

            first=first->next->next;

            second=second->next->next;

            swap(first->val,second->val);

        }

        return head;

    }

};