bool solve(Tree* root, int val) {
    
    if(!root)
        return false;

    if(root->val == val)
        return true;

    if(root->val < val)
        return solve(root->right, val);
    if(root->val > val)
        return solve(root->left,val);            

    return false;    
}
