/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 589.cpp
 * Created on : Thu Jun 10 2021
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
vector<int> res;
void findChild(Tree* root, int dist)
{
    if(!root)
        return;
    if(dist<=0)
    {
        if(dist==0)
            res.push_back(root->val);
        return;
    }
    findChild(root->left, dist-1);
    findChild(root->right, dist-1);
}

int findTarget(Tree* root, int radius, int target)
{
    if(!root)
        return -1;
    
    if(root->val == target)
    {
        findChild(root, radius);
        return 1;
    }

    int l = findTarget(root->left,radius, target);
    int r = findTarget(root->right,radius, target);

    if(l!=-1)
    {
        if(l==radius)
            res.push_back(root->val);
        else 
            findChild(root->right, radius-l-1);
        return l+1;
    }    
    else if(r!=-1)
    {
        if(r==radius)
            res.push_back(root->val);
        else 
            findChild(root->left, radius-r-1);
        return r+1;
    }   
    return -1;
}
vector<int> solve(Tree* root, int target, int radius) {
    res.clear();

    findTarget(root,radius, target);
    sort(res.begin(), res.end());
    return res;

}
