/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AllPossibleFullBinaryTrees.cpp
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
    vector<TreeNode*> formTree(int n)
    {
        if(n==2)
            return {};
        if(n==1)
            return {new TreeNode(0)};
          
        vector<TreeNode*> res;
        for(int i = 2; i<=n-1; i++)
        {
            vector<TreeNode*> left = formTree(i-1);
            vector<TreeNode*> right = formTree(n-i);
            
            for(TreeNode* l : left)
            {
                for(TreeNode* r : right)
                {
                    res.push_back(new TreeNode(0, l, r));
                }
            }
        }
        return res;
            
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        
        return formTree(n);
    }
};
    
/*
1 2 3 4 5 6 7 
  
1 2 3  
*/
