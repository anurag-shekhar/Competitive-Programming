/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindDuplicateSubtrees.cpp
 * Created on : Tue Jun 08 2021
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
    vector<TreeNode*> res;
    unordered_map<string, int> m;
    string treeHash(TreeNode* root)
    {
        if(!root)
            return "";
        string lHash = treeHash(root->left);
        string rHash = treeHash(root->right);
        
        string totalHash = to_string(root->val)+"-"+lHash+"-"+rHash;
        m[totalHash]++;
        if(m[totalHash] == 2)
            res.push_back(root);
        return totalHash;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        res.clear();
        m.clear();
        treeHash(root);
        return res;
        
    }
};
