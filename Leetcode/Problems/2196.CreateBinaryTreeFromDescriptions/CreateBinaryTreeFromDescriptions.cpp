/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CreateBinaryTreeFromDescriptions.cpp
 * Created on : Mon Jul 15 2024
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_map<int, bool> hasParent;
        for(auto desc : descriptions) {
            TreeNode* root = NULL;
            int parentVal = desc[0];
            int childVal = desc[1];
            int isLeft = desc[2];
            if(m.find(parentVal) != m.end()) {
                root = m[parentVal];
            } else {
                root = new TreeNode(parentVal);
                m[parentVal] = root;
            }
            TreeNode* child = NULL;
            if(m.find(childVal) != m.end()) {
                child = m[childVal];
            } else {
                child = new TreeNode(childVal);
                m[childVal] = child;
            }

            if(isLeft == 1)
                root->left = child;
            else 
                root->right = child;

            hasParent[childVal] = true;

            
        }
        TreeNode* realRoot = NULL;
        for(auto p : m) {
            if(hasParent[p.first] == false) {
                realRoot = p.second;
                break;
            }
        }
        return realRoot;
    }
};