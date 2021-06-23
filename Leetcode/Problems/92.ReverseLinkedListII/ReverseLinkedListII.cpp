/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReverseLinkedListII.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

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
    
    ListNode* reverse(ListNode* start, ListNode* end, ListNode* prev)
    {
        if(start == end)
        {
            end->next = prev;
            return end;
        }
        ListNode* temp = start->next;
        start->next = prev;
        return reverse(temp, end, start);
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* start = head, *end = head, *prev = NULL;
        
        while(left > 1)
        {
            prev = start;
            start = start->next;
            end  = end->next;
            left--;
            right--;
        }
        while(right > 1)
        {
            end  = end->next;
            right--;
        }
        
        ListNode* revHead = reverse(start, end, end->next);
        
        if(!prev)
            head = revHead;
        else 
            prev->next = revHead;
        
        return head;
        
        
        
    }
};
