/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DeleteNodesFromLinkedListPresentInArray.cpp
 * Created on : Mon Jul 15 2024
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int n : nums) {
            s.insert(n);
        }
        ListNode* itr = head, *prev = NULL;
        while(itr) {
            if(s.find(itr->val) != s.end()) {
                if(prev == NULL) {
                    head = itr->next;
                } else {
                    prev->next = itr->next;  
                }
            } else 
                prev = itr;
            itr = itr->next;
        }
        return head;
    }
};