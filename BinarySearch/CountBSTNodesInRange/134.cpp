/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 134.cpp
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
int solve(Tree* root, int lo, int hi) {
    if(!root)
        return 0;
    if(root->val < lo)
        return solve(root->right,lo,hi);
    else if(root->val > hi)
        return solve(root->left, lo, hi);
    else 
        return 1 + solve(root->left, lo, hi) + solve(root->right, lo, hi);             

}
