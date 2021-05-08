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
    long traversal(TreeNode* root, int &maxSum)
    {
        if(!root)
            return 0;
        int leftChild = traversal(root->left,maxSum);
        int rightChild = traversal(root->right, maxSum);
        
        int maxChild = max(leftChild, rightChild);
        int minChild = min(leftChild, rightChild);
        int maxPath = max(root->val, root->val+maxChild);
        maxSum = max(maxSum,max(maxPath,maxPath+minChild));
        return maxPath;    
            
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int maxSum = root->val;
        traversal(root,maxSum);
        return maxSum;
    }
};
