/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MiddleOfTheLinkedList.cpp
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        
        while(fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};