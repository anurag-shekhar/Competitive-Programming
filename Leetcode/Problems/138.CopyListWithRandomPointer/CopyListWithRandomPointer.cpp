/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CopyListWithRandomPointer.cpp
 * Created on : Tue Jun 29 2021
 ****************************************************************
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* getInterleaved(Node* head)
    {
        if(!head)
            return NULL;
        Node* newNode = new Node(head->val);
        Node* store = head->next;
        head->next = newNode;
        newNode->next = getInterleaved(store);
        return head;
    }
    void populateRandom(Node* head)
    {
        if(!head)
            return;
        if(head->random)
            head->next->random = head->random->next;
        else 
            head->next->random = NULL;
        populateRandom(head->next->next);
    }
    Node* extractCopyNode(Node* head)
    {
        if(!head)
            return NULL;
        Node* store = head->next->next;
        head->next->next = extractCopyNode(head->next->next);
        Node* newHead = head->next;
        head->next = store;
        
        return newHead;
    }
    Node* copyRandomList(Node* head) {
        
        head = getInterleaved(head);
        populateRandom(head);
        return extractCopyNode(head); 
    }
};
/*
1 ->1'-> 2 -> 3-> 4-> N
|    ^
| - -|
           
^    |
|- - |


 
*/
