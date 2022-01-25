/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RemoveDuplicatesFromSortedList.cpp
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
    ListNode* helper(ListNode* node, ListNode* prev)
    {
        if(prev)
            prev->next = node;
        if(!node)
            return node;
        if(prev && prev->val == node->val)
            return helper(node->next, prev);
        helper(node->next, node);
       
        return node;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        return helper(head, NULL);
    }
};
