/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 834.cpp
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

Tree* populateTree(vector<vector<Tree*> > &level, int depth) 
{
    if(depth == level.size())
        return NULL;
    
    if(level[depth].size()==0)
        return NULL;
    Tree* root = level[depth].back();
    root->right = populateTree(level,depth+1);
    root->left = populateTree(level,depth+1);
    level[depth].pop_back();
    return root;
}
void preorder(Tree* root, vector<vector<Tree*> > &level, int depth)
{
    if(!root)
        return;
    
    if(depth==level.size())
        level.push_back({root});  
    else 
        level[depth].push_back(root);

    preorder(root->left, level, depth+1);
    preorder(root->right, level, depth+1);        
}

Tree* solve(Tree* root) {
    vector<vector<Tree*> > level;
    preorder(root, level, 0);


    return populateTree(level, 0);
}
