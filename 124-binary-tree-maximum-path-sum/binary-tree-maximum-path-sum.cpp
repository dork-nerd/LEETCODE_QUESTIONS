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
    int maxi = -1001;
    int mps(TreeNode* root){
        if(root==nullptr) return 0;
        int l = mps(root->left);
        int r = mps(root->right);
        int sum = root->val + l + r;
        maxi = max({sum,root->val,maxi,root->val+l,root->val+r});
        return max({root->val,root->val+l,root->val+r});
    }
    int maxPathSum(TreeNode* root) {
        int sum = mps(root);
        return max(maxi,sum);
    }
};