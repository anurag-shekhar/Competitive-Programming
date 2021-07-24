/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LowestCommonAncestorOfBinarySearchTree.cpp
 * Created on : Sat Jul 24 2021
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root)
            return NULL;
        
        int val = root->val;
        int p_val = p->val;
        int q_val = q->val;
        
        if(p_val < val && q_val < val)
            return lowestCommonAncestor(root->left, p,q);
        else if(p_val > val && q_val > val)
            return lowestCommonAncestor(root->right, p,q);
        return root;
    }
};