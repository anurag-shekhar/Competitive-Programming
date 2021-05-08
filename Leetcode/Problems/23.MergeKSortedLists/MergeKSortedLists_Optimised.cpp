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
class compare
{
    public:
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode* , vector<ListNode*> , compare> minheap;
        for(int i = 0; i<lists.size(); i++)   
            if(lists[i])
                minheap.push(lists[i]);
        ListNode* res = NULL;
        ListNode* head = NULL;
        while(!minheap.empty())
        {
            ListNode* n = minheap.top();
            minheap.pop();
            if(n->next)
                minheap.push(n->next);
            if(!res)
            {
                res = n;
                head = res;
            }
            else 
            {
                res->next = n;
                res = res->next;
            }
            res->next = NULL;
        }
        return head;
    }
};
