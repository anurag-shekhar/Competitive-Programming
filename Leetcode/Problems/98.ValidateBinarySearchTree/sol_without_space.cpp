/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : sol_without_space.cpp
 * Created on : Wed May 12 2021
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
    bool inorder(TreeNode* root, long &prev)
    {
        if(!root)
            return true;
        if(!inorder(root->left, prev))
            return false;
        if(prev >= root->val)
            return false;
        else 
            prev = root->val;
        if(!inorder(root->right,prev))
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        
        long prev = LONG_MIN;
        if(inorder(root,prev))
            return true;
        return false;
    }
};
