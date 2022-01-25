/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 206.ReverseLinkedList.cpp
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
    ListNode* reverse(ListNode* &head, ListNode* node, ListNode* prev = NULL)
    {
        if(!node)
            return NULL;
        if(!node->next)
        {
            head = node;
            node->next = prev;
            return prev;
        }
        reverse(head, node->next, node)->next = prev;
        return prev;
    }
    ListNode* reverseList(ListNode* head) {
        reverse(head, head);
        return head;
    }
};