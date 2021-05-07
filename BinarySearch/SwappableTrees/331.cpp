/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree* root0, Tree* root1) {
    
    if(!root0 && !root1)
        return true;
    if(!root0 || !root1)
        return false;

    if(root0->val != root1->val)
        return false;
    else 
    {
        bool left = false, right = false;
        if(solve(root0->left, root1->left) && solve(root0->right, root1->right))
            left = true;
        if(solve(root0->left, root1->right) && solve(root0->right, root1->left))    
            right = true;
        
        return (left || right);
    }            
}
