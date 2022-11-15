/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountCompleteTreeNodes_method2.cpp
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
    
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        TreeNode* l =  root, *r = root;
        int lh = 0, rh =0;
        while(l) 
        {
            l = l->left;
            lh++;
        }
        while(r)
        {
            r = r->right;
            rh++;
        }
        
        if(lh == rh)
        {
            int localNodes = (1<<lh) -1;
            return localNodes;
        }
        else 
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
