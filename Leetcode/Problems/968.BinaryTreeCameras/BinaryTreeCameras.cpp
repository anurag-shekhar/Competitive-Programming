/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BinaryTreeCameras.cpp
 * Created on : Mon May 17 2021
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
    // -1 -> i'm not monitored
    // 0  -> i'm covered
    // 1 -> i have camera 
    int solve(TreeNode* root, int &cameras)
    {
        if(!root)
            return 0;
        
        int l = solve(root->left, cameras);
        int r = solve(root->right, cameras);
        
        if(l == -1 || r == -1)
        {
            cameras++;
            return 1;
        }
        if(l== 1 || r == 1)
            return 0;
        
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if(solve(root, cameras) == -1)
            cameras++;
        return cameras;
    }
};
