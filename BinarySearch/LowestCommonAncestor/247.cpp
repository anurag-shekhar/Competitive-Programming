/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 247.cpp
 * Created on : Fri May 14 2021
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
int solve(Tree* root, int a, int b) {

    if(!root)
        return -1;

    if(root->val == a || root->val == b)
        return a;
    int l = solve(root->left, a,b);  
    int r = solve(root->right, a, b); 

    if(l != -1 && r != -1)
        return root->val;
    else if(l == -1)
        return r;
    else 
        return l;

    return root->val;
}
