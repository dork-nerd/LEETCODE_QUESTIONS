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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int toggle = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> vec(size);
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                int index = 0;
                if(toggle==0) index = i;
                else index = size-1-i;
                vec[index] = temp->val;
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
            ans.push_back(vec);
            if(toggle) toggle=0;
            else toggle =1;
        }
        return ans;
    }
};