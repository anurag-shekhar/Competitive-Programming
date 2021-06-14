/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReorderList.cpp
 * Created on : Mon Jun 14 2021
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
        {
            return prev;
        }
        ListNode* temp = head->next;
        head->next = prev;
        return reverse(temp, head);
            
    }
    void reorderList(ListNode* head) {
        
        ListNode* slow = head, *prev = NULL;
        ListNode* fast = head;
        
        
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* list2= head, *list1 = head;
        if(fast)
        {
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        list2 = reverse(slow, NULL);
            
        
        ListNode* store;
        while(list2)
        {
            store = list1->next;
            list1->next = list2;
            list1 = store;
            store = list2->next;
            list2->next = list1;
            list2 = store;
        }
    }
};
