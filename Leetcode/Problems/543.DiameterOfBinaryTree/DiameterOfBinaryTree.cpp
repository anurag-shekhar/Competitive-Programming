/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DiameterOfBinaryTree.cpp
 * Created on : Fri May 14 2021
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
    int longestPath(TreeNode* root, int & res)
    {
        if(!root)
            return 0;
        int l = longestPath(root->left, res);
        int r = longestPath(root->right, res);
        
        int a = max(l,r);
        int b = min(l,r);
        int temp = 1+a;
        
        res = max(res, temp + b);
        return temp;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        longestPath(root, res);
        return res-1;
    }
};
