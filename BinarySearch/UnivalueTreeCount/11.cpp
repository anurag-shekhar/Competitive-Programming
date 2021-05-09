/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 11.cpp
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
bool univalue(Tree* root, int &count)
{

    if(!root)
        return true;
    bool l = univalue(root->left,count);
    bool r = univalue(root->right,count);

    if(!root->left && !root->right)
    {
        count++;
        return true;
    }    
    else if(!root->left)
    {
        if(root->val == root->right->val && r)
        {
            count++;
            return true;
        }  
    }    
    else if(!root->right ) 
    {
        if(root->val == root->left->val && l)
        {
            count++;
            return true;
        }    
    }
    else if(root->val == root->left->val && root->val == root->right->val && l && r)
    {
        count++;
        return true;
    }
    return false;
} 
int solve(Tree* root) {
    
    int count = 0;
    univalue(root, count);
    return count;

}
