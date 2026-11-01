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
    void summ(TreeNode* r){
        if(r==nullptr) return;
        if(r->left != nullptr && r->left->left==nullptr && r->left->right==nullptr){
            sum += r->left->val;
        }
        summ(r->left);
        summ(r->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        summ(root);
        return sum;
    }
};