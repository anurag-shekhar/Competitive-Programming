/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 730.cpp
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
void inorder(Tree* root, vector<int> &A)
{
    if(!root)
        return;
    inorder(root->left, A);
    A.push_back(root->val);
    inorder(root->right, A);
}
class BSTIterator {
    public:
    vector<int> A;
    int currIdx;
    BSTIterator(Tree* root) {
        inorder(root, A);
        currIdx = -1; 
    }

    int next() {
        return A[++currIdx];
    }

    bool hasnext() {
        return currIdx+1 < A.size();
    }
};
