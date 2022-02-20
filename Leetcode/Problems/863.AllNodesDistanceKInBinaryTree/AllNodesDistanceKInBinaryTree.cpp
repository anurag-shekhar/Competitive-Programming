/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AllNodesDistanceKInBinaryTree.cpp
 * Created on : Mon Feb 21 2022
 ****************************************************************
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void traversal(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent)
    {
        if(!root)
            return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        
        traversal(root->left, parent);
        traversal(root->right, parent);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;    
        traversal(root, parent);
        vector<int> res;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        while(k>=0)
        {
            if(k == 0)
            {
                while(!q.empty())
                {
                    res.push_back(q.front()->val);
                    q.pop();
                }
                return res; 
            }       
            
            int sz = q.size();
            for(int i = 0; i<sz; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited.count(node->left))
                {
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right && !visited.count(node->right))
                {
                    visited.insert(node->right);
                    q.push(node->right);
                }
                if(parent[node] && !visited.count(parent[node]))
                {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
            k--;
        }
        return res;
    }
};