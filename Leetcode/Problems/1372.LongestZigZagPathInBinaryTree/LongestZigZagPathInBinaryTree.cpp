/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestZigZagPathInBinaryTree.cpp
 * Created on : Mon Feb 21 2022
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
    void helper(TreeNode* root, bool isLeft, int step, int &res)
    {
        if(!root)
            return;
        res = max(step, res);
        
        if(isLeft)
        {
            helper(root->right, false, step+1, res);
            helper(root->left, true, 1, res);
        }
        else 
        {
            helper(root->left, true, step+1, res);
            helper(root->right, false, 1, res);
        }
    }
    int longestZigZag(TreeNode* root) {
        int res = 0;
        helper(root, true, 0, res);
        helper(root, false, 0, res);
        return res;
        
    }
};