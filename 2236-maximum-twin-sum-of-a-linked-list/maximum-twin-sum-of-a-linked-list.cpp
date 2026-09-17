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
    ListNode* temp = nullptr;
    int maxi = 0;
    void rec(ListNode* head,int n){
        if(n==0){
            temp = head;
            return;
        }
        rec(head->next,n-1);
        maxi = max(maxi,head->val+temp->val);
        temp = temp->next;
    }
    int pairSum(ListNode* head) {
        int size = 0;
        ListNode* t = head;
        while(t!=nullptr){
            t = t->next;
            size++;
        }
        rec(head,size/2);
        return maxi;
    }
};