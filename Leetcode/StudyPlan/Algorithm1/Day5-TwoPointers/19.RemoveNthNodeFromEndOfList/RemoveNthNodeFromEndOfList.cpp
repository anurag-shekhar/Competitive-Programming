/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RemoveNthNodeFromEndOfList.cpp
 * Created on : Sun Jan 23 2022
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* node = head, *prev = NULL;
        ListNode* last = head;
        while(--n)
        {
            last = last->next;
        }
        
        while(last->next)
        {
            prev = node; 
            node = node->next;
            last = last->next;
        }
        
        if(prev)
            prev->next = node->next;
        else 
            head = head->next;
        return head;
    }
};