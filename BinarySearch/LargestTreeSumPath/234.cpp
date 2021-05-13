/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 234.cpp
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
int travel(Tree* root, int &res)
{
    if(!root)
        return 0;
    int l = travel(root->left,res);
    int r = travel(root->right,res);
    
    int minChildPath = min(l,r);
    root->val = max(max(l,r)+root->val, root->val);
    
    res = max(res, max(root->val, root->val + minChildPath));
    return root->val;    
}

int solve(Tree* root) {
    int res = 0;
    travel(root, res);
    return res;
}
