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
    ListNode* reverse(ListNode* start, ListNode* end, ListNode* nextPtr)
    {
        if(start == end)
        {
            end->next = nextPtr;
            return end;
        }
        ListNode* t = start->next;
        start->next = nextPtr;
        return reverse(t,end,start);
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* start = head, *saved; 
        ListNode* end = head;
        ListNode* prev = NULL;
        int count = 1;
        
        while(end)
        {
            //cout<<end->val<<" ";
            if(count==k)
            {
                
                saved = end->next;
                if(!prev)
                    head = reverse(start,end,end->next);
                else 
                    prev->next = reverse(start,end,end->next);
                prev = start;
                end = saved;
                start = saved;
                count = 1;
            }
            else 
            {    
                end = end->next;
                count++;
            }
        }
        return head;
        
    }
};
