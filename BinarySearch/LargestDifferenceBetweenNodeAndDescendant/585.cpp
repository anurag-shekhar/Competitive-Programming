/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 585.cpp
 * Created on : Wed Jul 07 2021
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

int res;
vector<int> helper(Tree* root)
{
    if(!root)
        return {INT_MAX, INT_MIN};

    vector<int> l = helper(root->left);
    vector<int> r = helper(root->right);
    
    int leftBound = min(root->val, min(r[0], l[0]));
    int rightBound = max(root->val, max(r[1], l[1]));
    res = max(res, max(abs(leftBound - root->val), abs(rightBound - root->val)));
    return {leftBound, rightBound};
}
int solve(Tree* root) {
    res = 0;
    helper(root);
    return res;
}
