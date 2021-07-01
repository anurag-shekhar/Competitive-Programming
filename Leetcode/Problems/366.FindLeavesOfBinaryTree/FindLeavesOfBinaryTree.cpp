/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindLeavesOfBinaryTree.cpp
 * Created on : Thu Jul 01 2021
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
    
    int helper(TreeNode* root, vector<vector<int> > &res)
    {
        if(!root)
            return -1;
        
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        int val = 1+max(left, right);
        
        if(res.size() == val)
            res.push_back({root->val});
        else 
            res[val].push_back(root->val);
        
        return val;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        vector<vector<int> > res;
        helper(root, res);
        return res;
        
    }
};
