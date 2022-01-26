/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ValidateBinarySearchTree.cpp
 * Created on : Wed Jan 26 2022
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
    TreeNode* prev = NULL;
    bool helper(TreeNode* node)
    {
        if(!node)
            return true;
        if(!helper(node->left))
            return false;
        if(prev && prev->val >= node->val)
            return false;
        prev = node;
        if(!helper(node->right))
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        
        prev = NULL;
        return helper(root);
    }
};