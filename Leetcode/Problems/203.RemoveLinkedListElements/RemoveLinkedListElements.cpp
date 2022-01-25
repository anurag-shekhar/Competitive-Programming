/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RemoveLinkedListElements.cpp
 * Created on : Tue Jan 25 2022
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
    ListNode* helper(ListNode* node, ListNode* prev, int val)
    {
        if(prev)
            prev->next = node;
        if(!node)
            return NULL;
        if(node->val == val)
            return helper(node->next, prev, val);
        
        helper(node->next, node, val);
        return node;
    }
    ListNode* removeElements(ListNode* head, int val) {
        
        return helper(head, NULL, val);
    }
};
