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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp = head;
        if(temp==nullptr || temp->next==nullptr) return temp;
        ListNode* temp2 = head->next;
        ListNode* combine = temp2;
        while(temp!=nullptr && temp2!=nullptr && temp2->next!=nullptr){
            if(temp->next!=nullptr && temp->next->next!=nullptr) temp->next = temp->next->next;
            if(temp2->next!=nullptr) temp2->next = temp2->next->next;
            temp = temp->next;
            temp2 = temp2->next;
        }
        temp->next = combine;
        return head;
    }
};