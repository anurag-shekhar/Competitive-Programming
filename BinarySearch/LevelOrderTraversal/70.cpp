/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 70.cpp
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
vector<int> solve(Tree* root) {
    
    queue<Tree*> q;
    q.push(root);
    vector<int> res;
    while(!q.empty())
    {
        Tree* t = q.front();
        q.pop();

        res.push_back(t->val);

        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);    
    }
    return res;
}
