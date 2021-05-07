/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* node) {
    
    if(node && node->next)
    {   
        LLNode* nextPtr = node->next->next;
        node->next->next = node;
        LLNode* res = node->next;
        node->next = solve(nextPtr);
        return res;

    }
    else 
        return node;
}
