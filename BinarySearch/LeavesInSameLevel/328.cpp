/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 328.cpp
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
bool dfs(Tree* root,int currLevel, int &level)
{
    if(!root)
        return true;;
    if(!root->left && !root->right)  
    {
        if(level!=-1)
        {
            if(currLevel != level)
                return false;
            else 
                return true;    
        }
        else 
        {
            level = currLevel;
            return true;
        }
    }

    if(!dfs(root->left, currLevel+1, level))
        return false;
    if(!dfs(root->right, currLevel+1, level))
        return false;
    return true;    
             
}
bool solve(Tree* root) {
    int level = -1;
    return dfs(root, 0, level);
}
