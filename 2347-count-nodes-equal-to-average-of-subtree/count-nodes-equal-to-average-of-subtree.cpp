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
    int totalcount = 0;
    vector<int> avg(TreeNode* root){
        if(root==nullptr) return {0,0};
        vector<int> left = avg(root->left);
        vector<int> right = avg(root->right);
        int sum = root->val + left[0] + right[0];
        int count = left[1] + right[1] + 1;
        if(root->val==sum/count) totalcount++;
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        avg(root);
        return totalcount;
    }
};