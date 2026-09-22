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
     TreeNode* minnode(TreeNode* root){
        if(root==nullptr) return nullptr;
        TreeNode* temp = root;
        while(temp->left!=nullptr){
            temp =  temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else if(key<root->val){
            root->left = deleteNode(root->left,key);
        }
        else{
            if(root->right==nullptr){
                return root->left;
            }
            if(root->left==nullptr){
                return root->right;
            }
            TreeNode* min = minnode(root->right);
            root->right = deleteNode(root->right,min->val);
            root->val = min->val;
        }
        return root;
    }
};