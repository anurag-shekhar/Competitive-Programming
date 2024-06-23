/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BalanceBinarySearchTree.cpp
 * Created on : Sun Jun 23 2024
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
    void inorder_traversal(TreeNode* root,  vector<TreeNode*> &inorder) {
        if(root) {
            inorder_traversal(root->left, inorder);
            inorder.push_back(root);
            inorder_traversal(root->right, inorder);
        }
    }
    TreeNode* buildTree(vector<TreeNode*> &inorder, int left, int right) {
        if(left > right) 
            return NULL;
        if(left == right) {
            inorder[left]->left = NULL;
            inorder[left]->right = NULL;
            return inorder[left];
        }
        int mid = (left + right)/2;
        inorder[mid]->left = buildTree(inorder, left, mid-1);
        inorder[mid]->right = buildTree(inorder, mid+1, right);
        return inorder[mid];
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> inorder;
        inorder_traversal(root, inorder);
        return buildTree(inorder, 0, inorder.size()-1);
    }
};

/*

            1                  2
                3            1.   3
              2   4    ->           4
*/
