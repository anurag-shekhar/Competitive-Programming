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
    vector<int> A;
    int i;
    void inorder(TreeNode* root, vector<int> &A)
    {
        if(!root)
            return ;
        inorder(root->left,A);
        A.push_back(root->val);
        inorder(root->right,A);    
    }
    BSTIterator(TreeNode* root) {
        inorder(root, A);
        i=-1;
    }
    
    bool hasNext() {
        return i+1<A.size();
    }
    
    int next() {
        return A[++i];
    }
    
    bool hasPrev() {
        return i-1>=0;
    }
    
    int prev() {
        return A[--i];
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
