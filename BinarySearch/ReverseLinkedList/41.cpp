/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* reverse(LLNode* node, LLNode* prev) {
    if(!node)
        return prev;

    LLNode* nextPtr = node->next;
    node->next = prev;
    return reverse(nextPtr, node);

}

LLNode* solve(LLNode* node) {
   
    return reverse(node, NULL);

}

/*
1->2->3->4->N
*/
