/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 154.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node) {
    
    if(node && node->next)
    {   
        LLNode* nextPtr = node->next->next;
        node->next->next = node;
        LLNode* res = node->next;
        node->next = solve(nextPtr);
        return res;

    }
    else 
        return node;
}
