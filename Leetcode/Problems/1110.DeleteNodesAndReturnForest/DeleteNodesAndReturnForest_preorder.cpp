/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DeleteNodesAndReturnForest.cpp
 * Created on : Fri May 28 2021
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
    void deleteOperation(TreeNode* root,  unordered_set<int> &s,  unordered_map<int,TreeNode*> &m, TreeNode* prev, char dir)
    {
        if(!root)
            return;
        
        if(s.count(root->val))
        {
            if(m.count(root->val))
                m.erase(root->val);
            if(prev)
            {
                if(dir=='l')
                    prev->left = NULL;
                else
                    prev->right = NULL;
            }
            
            if(root->left)
                m[root->left->val] = root->left;
            if(root->right)
                m[root->right->val] = root->right;
        }
        
        deleteOperation(root->left, s, m, root, 'l');
        deleteOperation(root->right, s, m, root, 'r');
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        unordered_map<int,TreeNode*> m; 
        if(!root)
            return {};
        m[root->val] = root;
        deleteOperation(root, s, m, NULL, '#');
        
        vector<TreeNode* > res;
        for(auto p : m)
            res.push_back(p.second);
        return res;
    }
};
