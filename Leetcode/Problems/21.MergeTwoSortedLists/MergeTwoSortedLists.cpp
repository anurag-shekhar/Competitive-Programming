/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2,ListNode* prev1=NULL, ListNode* prev2 = NULL) {
        
        if(!l1 && !l2)
            return NULL;
        if(!l2)
            return l1;
        if(!l1)
            return l2;
        
        ListNode* t;
        if(l1->val <= l2->val)
        {    
            t = l1;
            l1 = l1->next;
            t->next = l2;
            if(prev2)
                prev2->next = t;
            mergeTwoLists(l1,l2,NULL,t);
        }
        else 
        {
            t = l2;
            l2 = l2->next;
            t->next = l1;
            if(prev1)
                prev1->next = t;
            mergeTwoLists(l1,l2,t,NULL);
            
        }
        return t;
        
        
        
    }
};
