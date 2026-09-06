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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int diff = 100001;
        int last = -1;
        ListNode* temp = head->next;
        int prev = head->val;
        int i = 0;
        while(temp->next!=nullptr){
            if(temp->val>prev && temp->val>temp->next->val){
                if(first==-1){
                    first = i;
                    last = i;
                }
                else{
                    diff = min(diff,i-last);
                    last = i;
                }
            }
            else if(temp->val<prev && temp->val<temp->next->val){
                if(first==-1){
                    first = i;
                    last = i;
                }
                else{
                    diff = min(diff,i-last);
                    last = i;
                }
            }
            i++;
            prev = temp->val;
            temp = temp->next;
        }
        if(first==last || first==-1) return {-1,-1};
        else return {diff,last - first};
    }
};