/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 435.cpp
 * Created on : Sun Jun 06 2021
 ****************************************************************
 */


/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */

LLNode* reverse(LLNode* prev, LLNode* head , LLNode* stop)
{
    if(head == stop)
    {
        head->next = prev;
        return head;
    }    

    LLNode* store = head->next;
    head->next = prev;
    return reverse(head, store, stop);
}

LLNode* solve(LLNode* node, int i, int j) {
    
    LLNode* prev = NULL;

    LLNode* start = node, *end = node;

    while(i && j)
    {
        prev = start;
        start = start->next;
        end = end->next;
        i--;
        j--;
    }
    while(j)
    {
        end = end->next;
        j--; 
    }

    //cout<<start->val<<" "<<end->val<<endl;

    LLNode* revHead = reverse(end->next, start,end);
    if(prev)
    {
        prev->next = revHead;
    }
    else 
        node = revHead;
    
    return node;

}
