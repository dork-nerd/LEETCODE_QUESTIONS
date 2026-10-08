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
class Solution {
public:
    TreeNode* split(int st,int l,int r,vector<int> &pre,vector<int> &in){
        TreeNode* empty ;
        if(l>r) return nullptr;
        empty = new TreeNode(pre[st]);
        int index = 0;
        for(int i=l;i<=r;i++){
            if(empty->val==in[i]){
                index = i;
            }
        }
        empty->left = split(st+1,l,index-1,pre,in);
        empty->right = split(st+(index-l)+1,index+1,r,pre,in);
        return empty;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = split(0,0,inorder.size()-1,preorder,inorder);
        return root;
    }
};