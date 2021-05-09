/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 762.cpp
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
void inorder(Tree* root, vector<int> &A)
{
    if(!root)
        return ;
    inorder(root->left,A);
    A.push_back(root->val);
    inorder(root->right,A);    
}

class BSTIterator {
    public:
    vector<int> A;
    int i;
    BSTIterator(Tree* root) {
        inorder(root, A);
        i=-1;
    }

    int next() {
        return A[++i];
    }

    bool hasnext() {
        return i+1<A.size();
        
    }

    int prev() {
        return A[--i];
    }

    bool hasprev() {
        return i-1>=0;
    }
};
