/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 276.cpp
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
Tree* solve(Tree* root) {

    if(!root)
        return NULL;

    int res = 0;

    Tree* leftTree = solve(root->left);
    Tree* rightTree = solve(root->right);
    
    if(leftTree)
        res += leftTree->val;
    if(rightTree)
        res += rightTree->val;

    root->val += res;
    return root;        
    
}
