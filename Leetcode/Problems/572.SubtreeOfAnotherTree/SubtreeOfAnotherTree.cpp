/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SubtreeOfAnotherTree.cpp
 * Created on : Mon Jun 14 2021
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
    
    unordered_map<TreeNode*, string> hash;
    
    string getHash(TreeNode* root)
    {
        
        if(!root)
            return "";
        
        if(hash.count(root))
            return hash[root];
        string l = getHash(root->left);
        string r = getHash(root->right);
        
        string h = to_string(root->val) + "-" + l + "-" + r;
        
        hash[root] = h;
        return hash[root];
    }
    
    bool checkSubtree(TreeNode* root, string target)
    {
        if(!root)
            return false;
        
        if(getHash(root) == target)
            return true;
        
        if(checkSubtree(root->left, target) || checkSubtree(root->right, target))
            return true;
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        string targetHash = getHash(subRoot);
    
        return checkSubtree(root, targetHash);
        
        
    }
};
