/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : sol_dfs.cpp
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
    
    void preorder(vector<vector<int> > &res,TreeNode* root,int level)
    {
        if(!root)
            return;
        if(res.size() == level)
            res.push_back({});
        res[level].push_back(root->val);
        preorder(res,root->left,level+1);
        preorder(res,root->right,level+1);
         
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
          
        vector<vector<int> > res;
        preorder(res,root,0);
    
        return res;
        
        
        
    }
};
