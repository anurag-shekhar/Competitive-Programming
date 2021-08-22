/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountGoodNodesInBinaryTree.cpp
 * Created on : Sun Aug 22 2021
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
    
    int goodNodes(TreeNode* root, int lastVal = INT_MIN) {
        
        if(!root)
            return 0;
        int count = 0;
        
        if(root->val >= lastVal)
            count = 1;
        
        lastVal = max(root->val, lastVal);
        count += goodNodes(root->left, lastVal);
        count += goodNodes(root->right, lastVal);
        
        return count;
    }
};
