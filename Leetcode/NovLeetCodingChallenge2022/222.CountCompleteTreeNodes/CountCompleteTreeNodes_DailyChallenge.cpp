/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : CountCompleteTreeNodes_DailyChallenge.cpp
 * Created on : Wed Nov 16 2022 
 ***************************************************************
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
    /* SOLUTION 1 
    int countNodes(TreeNode* root) {

        if(root == NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    */
    /* Solution 2 */
    int countNodes(TreeNode* root) {

        if(root == NULL)
            return 0;
        int leftHeight = 0, rightHeight = 0;
        TreeNode* left= root, *right = root;
        
        while(left) {
            left = left->left;
            leftHeight++;
        }
        while(right) {
            right = right->right;
            rightHeight++;
        }

        if(leftHeight == rightHeight) 
            return (1<<rightHeight) - 1; 
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};