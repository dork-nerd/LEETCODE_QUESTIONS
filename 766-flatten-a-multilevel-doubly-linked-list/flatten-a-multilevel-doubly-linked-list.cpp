/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        vector<Node*> vec;
        Node* dummy = head;
        Node* pre = nullptr;
        Node* chi = nullptr;
        while(dummy!=nullptr){
            if(dummy->child!=nullptr){
                if(dummy->next!=nullptr) vec.push_back(dummy->next);
                pre = dummy;
                chi = dummy->child;
                dummy->child=nullptr;
                dummy->next = chi;
                dummy = dummy->next;
                dummy->prev = pre;
                continue;

            }
            else{
                if(dummy->next==nullptr){
                    break;
                }
                else{
                    dummy = dummy->next;
                }
            }
        }
        for(int i=vec.size()-1;i>=0;i--){
            vec[i]->prev = dummy;
            dummy->next = vec[i];
            while(dummy->next!=nullptr){
                dummy = dummy->next;
            }
        }
        return head;
    }
};