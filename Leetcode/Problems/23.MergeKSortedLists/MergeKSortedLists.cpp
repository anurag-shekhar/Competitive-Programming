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
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2, ListNode* prev1, ListNode* prev2)
    {
        if(!l1 && !l2)
            return NULL;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        ListNode* t;
        if(l1->val <= l2->val)
        {
            t = l1; 
            l1 = l1->next;
            t->next = l2;
            if(prev2)
                prev2->next = t;
            mergeTwoList(l1,l2,NULL,t);
        }
        else 
        {
            t = l2; 
            l2 = l2->next;
            t->next = l1;
            if(prev1)
                prev1->next = t;
            mergeTwoList(l1,l2,t,NULL);
        }
        return t;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head = NULL;
        int n = lists.size();
        if(n==0)
            return head;
        head = lists[0];
        for(int i = 1; i<n; i++)
            head = mergeTwoList(head,lists[i], NULL,NULL);
        return head;
    }
};
