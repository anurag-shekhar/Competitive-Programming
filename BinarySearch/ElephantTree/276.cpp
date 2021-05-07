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

    int res = 0;

    Tree* leftTree = solve(root->left);
    Tree* rightTree = solve(root->right);
    
    if(leftTree)
        res += leftTree->val;
    if(rightTree)
        res += rightTree->val;

    root->val += res;
    return root;        
    
}
