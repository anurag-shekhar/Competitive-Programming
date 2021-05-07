/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void build(Tree* root, int &leaves, int &totalNodes)
{
    if(!root)
        return;
    totalNodes++;
    if(!root->left && !root->right)
        leaves++;
    build(root->left, leaves, totalNodes);
    build(root->right, leaves, totalNodes);
    return ;     
}  
vector<int> solve(Tree* root) {
    int leaves = 0, totalNodes = 0;

    build(root, leaves, totalNodes);

    return {leaves, totalNodes - leaves};

}
