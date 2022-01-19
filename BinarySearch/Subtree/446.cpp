/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 446.cpp
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

bool helper(Tree* root, Tree* target)
{
    if(!root && !target)
        return true;
    if(!root || !target)
        return false;
    if(root->val != target->val)
        return false;
    if(!helper(root->left, target->left) || !helper(root->right, target->right))
        return false;
    return true;
    
}

bool solve(Tree* root, Tree* target) {

    if(!root)
        return false;
    if(helper(root, target))
        return true;
    if(solve(root->left, target))
        return true;
    if(solve(root->right, target))
        return true;
    return false;    
}
