/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BinaryTreeColoringGame.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

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
    int countNodes(TreeNode* root)
    {
        if(!root)
            return 0;
        int l  = countNodes(root->left);
        int r = countNodes(root->right);
        return 1+l+r;
    }
    TreeNode* findNode(TreeNode* root, int x)
    {
        if(!root)
            return NULL;
        TreeNode* l = findNode(root->left, x);
        if(l)
            return l;
        if(root->val == x)
                return root;
        TreeNode* r = findNode(root->right, x);
        if(r)
            return r;
        return NULL;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        TreeNode* xNode = findNode(root,x);
        int leftCount = countNodes(xNode->left);
        int rightCount = countNodes(xNode->right);
        int totalCount = countNodes(root);
        int parentCount = totalCount - (1+leftCount+rightCount);
        
        if(parentCount > totalCount/2 || leftCount > totalCount/2 || rightCount > totalCount/2)
            return true;
        return false;
        
    }
};
