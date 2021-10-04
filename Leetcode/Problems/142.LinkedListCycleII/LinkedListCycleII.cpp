/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LinkedListCycleII.cpp
 * Created on : Mon Oct 04 2021
 ****************************************************************
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode* slow = head->next;
        if(!slow)
            return NULL;
        ListNode* fast = head->next->next;
        
        while(slow != fast && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(!fast || !fast->next)
            return NULL;
        
        fast = head;
        
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        
        
        
        
        
        
        
    }
};
