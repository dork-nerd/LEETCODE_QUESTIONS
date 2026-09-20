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
    vector<vector<int>> ans;
    void ps(TreeNode* root,int target,vector<int> vec,int curr){
        vec.push_back(root->val);
        curr+=root->val;
        if(root->right==nullptr && root->left==nullptr){
            if(curr==target){
                ans.push_back(vec);
                return;
            }
            else return;
        }
        if(root->right==nullptr){
            ps(root->left,target,vec,curr);
            return;
        }
        if(root->left==nullptr){
            ps(root->right,target,vec,curr);
            return;
        }
        ps(root->right,target,vec,curr);
        ps(root->left,target,vec,curr);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return{};
        ps(root,targetSum,{},0);
        return ans;
    }
};