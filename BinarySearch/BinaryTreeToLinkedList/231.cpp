/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 231.cpp
 * Created on : Thu May 13 2021
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

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
void inorder(Tree* root, LLNode* &head, LLNode* &tail)
{
    if(!root)
        return;

    inorder(root->left, head, tail);
    if(!tail)
    {
        head = new LLNode(root->val);
        tail = head;
    }
    else 
    {
        LLNode* temp = new LLNode(root->val);
        tail->next = temp;
        tail = tail->next;
    }
    inorder(root->right, head, tail);
}
LLNode* solve(Tree* root) {

    LLNode* head = NULL;
    LLNode* tail = NULL;
    inorder(root, head, tail);
    return head;


    
}
