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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head==nullptr) return head;
        vector<int> vec(100001);
        ListNode* dummy = new ListNode();
        ListNode* d = dummy;
        for(int i:nums){
            vec[i]++;
        }
        while(head!=nullptr){
            if(vec[head->val]==0){
                d->next = new ListNode(head->val);
                d = d->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};