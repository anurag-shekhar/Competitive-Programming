/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumDepthOfBinaryTree.cpp
 * Created on : Tue Jan 25 2022
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
    int helper(TreeNode* root, int height)
    {
        if(!root)
            return height;
        if(!root->left && !root->right)
            return height;
        return max(helper(root->left, height+1), helper(root->right, height+1));
    }
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return helper(root, 1);
    }
};