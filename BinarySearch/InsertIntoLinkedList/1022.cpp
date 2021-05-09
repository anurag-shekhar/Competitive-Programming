/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 1022.cpp
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
LLNode* solve(LLNode* head, int pos, int val) {

    LLNode* i = head;

    if(pos==0)
    {
        LLNode* newnode = new LLNode(val);
        newnode->next = i;
        return newnode;
    }
    while(pos>1)
    {
        i = i->next;
        pos--;
    }

    LLNode* nextPtr = i->next;

    LLNode* newnode = new LLNode(val);

    i->next = newnode;
    newnode->next = nextPtr;
    return head;
    
        
    
}
