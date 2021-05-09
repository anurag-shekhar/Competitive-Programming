/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 1023.cpp
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
int traversal(Tree* root, int &res) 
{
    if(!root)
        return 0;
    int l = traversal(root->left, res);
    int r = traversal(root->right, res);

    root->val += l;
    root->val += r;        

    res = max(res, max(root->val, max(l , r)));

    return root->val;

}
int solve(Tree* root ) {

    int res = 0;
    traversal(root, res); 
    return res;


    
}
