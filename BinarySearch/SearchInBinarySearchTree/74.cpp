/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 74.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool solve(Tree* root, int val) {
    
    if(!root)
        return false;

    if(root->val == val)
        return true;

    if(root->val < val)
        return solve(root->right, val);
    if(root->val > val)
        return solve(root->left,val);            

    return false;    
}
