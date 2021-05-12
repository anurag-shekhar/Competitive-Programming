/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : InorderSuccessorInBST.cpp
 * Created on : Wed May 12 2021
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
    bool inorder(TreeNode* root, TreeNode* p, TreeNode* &prev)
    {
        
        if(!root)
            return false;
        if(inorder(root->left, p,prev))
            return true;
        if(prev == p)
        {
            prev = root;
            return true;
        }
        prev = root;
        if(inorder(root->right, p,prev))
            return true;
        return false;
            
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* prev = NULL;
        if(inorder(root,p,prev))
            return prev;
        return NULL;
    }
};
