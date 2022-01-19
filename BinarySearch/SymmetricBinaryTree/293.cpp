/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 293.cpp
 * Created on : Wed Jan 19 2022
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
bool helper(Tree* left, Tree* right)
{
    if(!left && !right)
        return true;
    if(!left || !right)
        return false;
    
    if(left->val != right->val)
        return false;
    
    if(!helper(left->left, right->right) || !helper(left->right, right->left))
        return false;
    return true;
}
bool solve(Tree* root) {
    
    if(!root)
        return true;
    return helper(root->left, root->right);
}
