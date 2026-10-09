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
    int sum = 0;
    TreeNode* rec(TreeNode* r){
        if(r==nullptr) return r;;
        r->right = rec(r->right);
        sum += r->val;
        r->val = sum;
        r->left = rec(r->left);
        return r;
    }
    TreeNode* bstToGst(TreeNode* root) {
        root = rec(root);
        return root;
    }
};