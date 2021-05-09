/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 869.cpp
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

int rightDepth(Tree* root, int level)
{
    if(!root)
        return level;
    return rightDepth(root->right,level+1);    
}
int leftDepth(Tree* root, int level)
{
    if(!root)
        return level;
    return leftDepth(root->left,level+1);    
}
int solve(Tree* root) {

    if(!root)
        return 0;
    int leftHeight = leftDepth(root->left, 0);    
    int rightHeight = rightDepth(root->right, 0);
    //cout<<leftHeight<<" "<<rightHeight<<endl;

    if(leftHeight == rightHeight)
        return ((1<<(leftHeight+1))-1);
    return solve(root->left) + 1 + solve(root->right);        
}
