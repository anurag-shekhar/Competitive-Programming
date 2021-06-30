/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DeleteNodesAndReturnForest_postorder.cpp
 * Created on : Wed Jun 30 2021
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
    vector<TreeNode*> forest;
    unordered_set<int> toDelete;
    void deleteNode(TreeNode* root,TreeNode* prev,bool isLeft)
    {
        if(!root)
            return;
        deleteNode(root->left, root, true);
        deleteNode(root->right, root, false);
        if(toDelete.count(root->val))
        {
            if(root->left)
                forest.push_back(root->left);
            if(root->right)
                forest.push_back(root->right);
            if(prev)
            {
                if(isLeft)
                    prev->left = NULL;
                else 
                    prev->right=NULL;
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        toDelete.clear();
        forest.clear();
        for(int a : to_delete)
            toDelete.insert(a);
        if(root &&!toDelete.count(root->val))
            forest.push_back(root);        
        deleteNode(root, NULL, true);
        return forest;
    }
};