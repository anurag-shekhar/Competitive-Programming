/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool traverse(Tree* root, int val)
{
    if(!root)
        return true;
    if(root->val != val)
        return false;    
    if(!traverse(root->left, val))    
        return false;
    if(!traverse(root->right, val))    
        return false;   
    return true;     
} 
bool solve(Tree* root) {
    int val = root->val;
    return traverse(root, val);    
}
