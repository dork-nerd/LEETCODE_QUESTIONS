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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #define rep(i,a,b) for(int i=a;i<b;i++)
class Solution {
public:
    TreeNode* binTree(int l,int r, vector<int>& vec){
        if(l>r) return nullptr;
        int mid = l + (r-l)/2;
        TreeNode* t = new TreeNode(vec[mid]);
        t->left = binTree(l,mid-1,vec);
        t->right = binTree(mid+1,r,vec);
        return t;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        while(head!=nullptr){
            vec.push_back(head->val);
            head = head->next;
        }
        if(vec.size()==0) return nullptr;
        TreeNode* root = binTree(0,vec.size()-1,vec);
        return root;
    }
};