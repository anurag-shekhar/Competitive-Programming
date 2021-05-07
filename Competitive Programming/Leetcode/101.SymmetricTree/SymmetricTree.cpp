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
    bool symTest(TreeNode* lChild, TreeNode* rChild)
    {
        if(!lChild && !rChild)
            return true;
        if(!lChild || !rChild)
            return false;
        
        if(lChild->val != rChild->val)
            return false;
        if(!symTest(lChild->right, rChild->left))
            return false;
         if(!symTest(lChild->left, rChild->right))
            return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return symTest(root->left,root->right);
    }
};
