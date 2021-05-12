/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AddTwoNumbers.cpp
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int len1 = 0, len2 = 0;
        ListNode* list1 = l1, *list2 = l2;
        while(list1)
        {
            list1 = list1->next;
            len1++;
        }
        while(list2)
        {
            list2 = list2->next;
            len2++;
        }
        
        if(len2 > len1)
            return addTwoNumbers(l2,l1);
        
        
        
        ListNode* head = l1; 
        
        
        int value, carry=0;
        ListNode *prev;
        while(l1 && l2)
        {
            //cout<<l1->val<<" + "<<l2->val<<" = ";
            value = l1->val + l2->val + carry;
            //cout<<value<<" % 10 = ";
            l1->val = value%10;
            carry = value/10;
            //cout<<l1->val<<" and carry : "<<carry<<endl;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        l1 = prev;
        l1 = l1->next;
        while(l1)
        {
            value = l1->val + carry;
            l1->val = value%10;
            carry = value/10;
            prev = l1;
            l1 = l1->next;
        }
        l1 = prev;
        if(carry > 0)
        {
            ListNode* node = new ListNode(carry);
            l1->next = node;    
        }
        return head;
        
        
    }
};
