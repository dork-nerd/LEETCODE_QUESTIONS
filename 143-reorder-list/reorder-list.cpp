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
    ListNode* dummy = new ListNode(0);
    ListNode* start; 
    void rec(ListNode* Node){
        if(Node==nullptr) return;
        rec(Node->next);
        if(start==Node){
            dummy->next = start;
            dummy = dummy->next;
            return;
        }
        dummy->next = start;
        start = start->next;
        dummy = dummy->next;
        dummy->next = Node;
        dummy = dummy->next;
        return;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        start = head;
        rec(slow);
        dummy->next = nullptr;
        return;
    }
};