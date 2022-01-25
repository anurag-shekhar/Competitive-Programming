/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SymmetricTree.cpp
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
    bool helper(TreeNode* a, TreeNode* b)
    {
        if(!a && !b)
            return true;
        if(!a || !b)
            return false;
        
        if(a->val != b->val)
            return false;
        if(!helper(a->left, b->right) || !helper(a->right, b->left))
            return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        
        if(!root)
            return true;
        return helper(root->left, root->right);
    }
};