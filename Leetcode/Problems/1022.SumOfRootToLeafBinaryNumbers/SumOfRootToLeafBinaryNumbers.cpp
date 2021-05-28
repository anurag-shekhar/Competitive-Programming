/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SumOfRootToLeafBinaryNumbers.cpp
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
    
    void evaluate(TreeNode* root, int val, int &res)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            res += val*2+root->val;
            return;
        }
        evaluate(root->left,val*2 + root->val ,res);
        evaluate(root->right,val*2 + root->val, res);
    }
    int sumRootToLeaf(TreeNode* root) {
        
        int res = 0;
        evaluate(root, 0, res);
        return res;
        
    }
};
