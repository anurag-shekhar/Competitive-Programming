/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BinaryTreeLevelOrderTraversal_onlyBFS.cpp
 * Created on : Thu May 20 2021
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int> > res;
        if(!root)
            return res;
        
        queue<pair<TreeNode*,int> > q;
        q.push({root,0});
        
        while(!q.empty())
        {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            
            if(res.size() == p.second)
                res.push_back({p.first->val});
            else
                res[p.second].push_back(p.first->val);
            
            if(p.first->left)
                q.push({p.first->left, p.second+1});
            if(p.first->right)
                q.push({p.first->right, p.second+1});
        }
        return res;
    }
};
