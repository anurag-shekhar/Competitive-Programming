/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 91.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void inorder(Tree* root, vector<int> &res)
{
    if(!root)
        return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);    
} 
vector<int> solve(Tree* root) {
    
    vector<int> res;
    inorder(root, res);
    return res;
    

}
