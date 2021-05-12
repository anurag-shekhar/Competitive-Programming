/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PalindromeLinkedList.cpp
 * Created on : Wed May 12 2021
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
    ListNode* reverse(ListNode* head, ListNode* prev)
    {
        if(!head)
            return prev;
        ListNode* next = head->next;
        head->next = prev;
        return reverse(next, head);
            
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *end, *start = head;
        if(!fast)
            end = reverse(slow, NULL);
        else 
            end = reverse(slow->next, NULL);
        
        while(end)
        {
            if(end->val != start->val)
                return false;
            end = end->next;
            start = start->next;
        }
        return true;
    }
};
