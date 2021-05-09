/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 249.cpp
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
void preorder(Tree* root, map<int, int> &m)
{
    queue<pair<Tree*,int> > q;
    q.push({root,0});

    while(!q.empty())
    {
        pair<Tree*, int> t = q.front();
        q.pop();
        if(m.find(t.second)==m.end())
            m[t.second] = t.first->val;

        if(t.first->left)
            q.push({t.first->left,t.second-1});
        if(t.first->right)
            q.push({t.first->right,t.second+1});        
    }      
}

vector<int> solve(Tree* root) {

    map<int, int> m;

    preorder(root,m);
    vector<int> res;
    for(pair<int,int> p : m)
        res.push_back(p.second);
    return res;
}
