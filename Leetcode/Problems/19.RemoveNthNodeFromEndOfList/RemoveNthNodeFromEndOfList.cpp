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
        ListNode* NodeToBeDeleted = head;
        ListNode* tillLastNode = head;
        ListNode* prev = NULL;
        while(n!=1)
        {
            n--;
            tillLastNode = tillLastNode->next;
        }
        
        while(tillLastNode->next)
        {
            prev = NodeToBeDeleted;
            NodeToBeDeleted = NodeToBeDeleted->next;
            tillLastNode = tillLastNode->next;
        }
        if(!prev)
            head = NodeToBeDeleted->next;   
        else 
            prev->next = NodeToBeDeleted->next;
        return head;
    }
};
/*
1,2,3,4,5
^
*/
