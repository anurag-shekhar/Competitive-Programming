/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : StepByStepDirectionsFromBinaryTreeNodeToAnother.cpp
 * Created on : Wed Jul 17 2024
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
    TreeNode* LCA(TreeNode* root, int startValue, int destValue) {
        if(root) {
            if(root->val == startValue || root->val == destValue) {
                return root;
            }
            TreeNode* left = LCA(root->left, startValue, destValue);
            TreeNode* right = LCA(root->right, startValue, destValue);
            if(right == NULL)
                return left;
            if(left == NULL)
                return right;
            return root;
        }
        return NULL:
    }
    bool directionHelper(TreeNode* src, int val, string path) {
        if(src) {
            if(src->val == val)
                return true;
            path += 'L';
            if(directionHelper(src->left, val, path))
                return true;
            path.pop_back();
            path += 'R';
            if(directionHelper(src->left, val, path))
                return true;
            path.pop_back();
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* lca = LCA(root, startValue, destValue);
        string root_start = "", root_dest = "";
        directionHelper(lca, startValue, root_start);
        directionHelper(lca, destValue, root_dest);

        for(char ch : root_start) {
            ch = 'U';
        }
        return root_start + root_dest;
    }
};