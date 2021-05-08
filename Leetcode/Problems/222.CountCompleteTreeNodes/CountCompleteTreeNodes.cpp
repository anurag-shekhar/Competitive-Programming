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
    
    /**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

    int rightDepth(TreeNode* root, int level)
    {
        if(!root)
            return level;
        return rightDepth(root->right,level+1);    
    }
    int leftDepth(TreeNode* root, int level)
    {
        if(!root)
            return level;
        return leftDepth(root->left,level+1);    
    }
    int countNodes(TreeNode* root) {

        if(!root)
            return 0;
        int leftHeight = leftDepth(root->left, 0);    
        int rightHeight = rightDepth(root->right, 0);
        //cout<<leftHeight<<" "<<rightHeight<<endl;

        if(leftHeight == rightHeight)
            return ((1<<(leftHeight+1))-1);
        return countNodes(root->left) + 1 + countNodes(root->right);        
    }
};
