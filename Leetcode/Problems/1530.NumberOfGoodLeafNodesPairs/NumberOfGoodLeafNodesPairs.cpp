/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfGoodLeafNodesPairs.cpp
 * Created on : Fri Jul 19 2024
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
    unordered_map<int, int> helper(TreeNode* root, int distance, int &result) {
        if(root) {
            if(!root->left && !root->right) {
                return {{1,1}};
            }
            unordered_map<int, int> left, right;
            if(root->left)
                left = helper(root->left, distance, result);
            if(root->right) 
                right = helper(root->right, distance, result);
            unordered_map<int,int> merge; 
            if(left.size() > 0 && right.size() > 0) {
                for(auto p1 : left) {
                    for(auto p2 : right) {
                        if(p1.first + p2.first <= distance) {
                            result += p1.second*p2.second;
                        }
                    }
                }
            }
            for(auto p : left) {
                if(p.first+1 < distance) {
                    merge[p.first+1] += p.second;
                }
            }
            for(auto p : right) {
                if(p.first+1 < distance) {
                    merge[p.first+1] += p.second;
                }
            }
            return merge;
        } 
        return {};
    }
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        helper(root, distance, result);
        return result;
    }
};