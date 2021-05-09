/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 129.cpp
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
class metric
{
    public:
    int minVal;
    int maxVal;
    int numNodes;
    metric(int a, int b, int c) : minVal(a), maxVal(b), numNodes(c) {}
};

metric* find(Tree* root, Tree* &res, int &numNodes)
{
    if(!root)
        return NULL;
    metric* leftMetric = find(root->left, res, numNodes);
    metric* rightMetric = find(root->right, res, numNodes);

    metric* m = new metric(root->val, root->val, 1);
    if(leftMetric && rightMetric)
    {
        if(leftMetric->maxVal < root->val && rightMetric->minVal > root->val)
        {
            m->minVal = min(m->minVal, leftMetric->minVal);
            m->numNodes += leftMetric->numNodes;   
            m->maxVal = max(m->maxVal, rightMetric->maxVal);
            m->numNodes += rightMetric->numNodes;
        }    
    }
    if(m->numNodes > numNodes)
    {
         res = root;
         numNodes = m->numNodes;
    }   
    return m;    

}
Tree* solve(Tree* root) {
    Tree* res = NULL;
    int numNodes = 0;
    find(root, res, numNodes);
    return res;  
}
