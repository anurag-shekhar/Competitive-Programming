/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* solve(Tree* root) {

    if(!root)
        return NULL;
    Tree* temp = root->left;    
    root->left = solve(root->right);
    root->right = solve(temp);
    return root;    
    
}
