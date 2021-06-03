/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 211.cpp
 * Created on : Fri Jun 04 2021
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

int res ; 

int helper(Tree* root)
{
    if(!root)
        return -1;

    int l = helper(root->left);
    int r = helper(root->right);
    
    int totalPath = 2 + l + r;

    res = max(res, totalPath);
    return max(1+l, 1+r);

}
int solve(Tree* root) {
    
    res = 0;
    helper(root);
    if(res == 0)
        return 0;
    return res+1;
}
