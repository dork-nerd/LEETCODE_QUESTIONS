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
class BSTIterator {
public:
    vector<int> vec;
    int index = -1;
    BSTIterator(TreeNode* root) {
        add(root);
    }
    
    int next() {
        index++;
        return vec[index];
    }
    
    bool hasNext() {
        if(index+1==vec.size()) return false;
        return true;
    }
    void add(TreeNode* r){
        if(r==nullptr)return;
        add(r->left);
        vec.push_back(r->val);
        add(r->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */