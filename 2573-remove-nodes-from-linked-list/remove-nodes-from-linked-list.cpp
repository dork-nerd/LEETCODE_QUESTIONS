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
    int great = 0;
    ListNode* dummy = nullptr;
    void rec(ListNode* head){
        if(head->next==nullptr){
            great = head->val;
            head->next = dummy;
            dummy = head;
            return;
        }
        rec(head->next);
        if(head->val>=great){
            great = head->val;
            head->next = dummy;
            dummy = head;
        }
        return;
    }
    ListNode* removeNodes(ListNode* head) {
        rec(head);
        return dummy;
    }
};