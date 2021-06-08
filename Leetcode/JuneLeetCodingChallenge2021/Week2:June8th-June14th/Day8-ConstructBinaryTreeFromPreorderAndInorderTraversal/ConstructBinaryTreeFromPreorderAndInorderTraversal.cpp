/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
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
    unordered_map<int, int> m;
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pos, int end)
    {
        if(pos >= end)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[pos]);
        int idx = m[preorder[pos]];
        
        int leftIdx = pos+1;
        int rightIdx = pos+1;
        while(rightIdx<end && idx > m[preorder[rightIdx]])
            rightIdx++;
        
        root->left = build(preorder, inorder, leftIdx,rightIdx);
        root->right = build(preorder, inorder, rightIdx,end);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        m.clear();
        int n = inorder.size();
        for(int i = 0;i < n ;i++)
        {
            m[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, n);
    }
};

/*
            1
      2             3
  4.      5.    6        7
  
  pre = 1 2 4 5 3 6 7
  in =  4 2 5 1 6 3 7
  
*/
