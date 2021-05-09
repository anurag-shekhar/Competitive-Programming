/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 251.cpp
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
bool traverse(Tree* root, int val)
{
    if(!root)
        return true;
    if(root->val != val)
        return false;    
    if(!traverse(root->left, val))    
        return false;
    if(!traverse(root->right, val))    
        return false;   
    return true;     
} 
bool solve(Tree* root) {
    int val = root->val;
    return traverse(root, val);    
}
