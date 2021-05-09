/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 254.cpp
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

int traverse(Tree* root, char ch)
{
    if(!root)
        return 0;    

    if(!root->left && !root->right && ch == 'R')
        return root->val;    

    return traverse(root->left, 'L') + traverse(root->right, 'R');    
}

int solve(Tree* root) {
    return traverse(root->left,'L') + traverse(root->right,'R')
}
