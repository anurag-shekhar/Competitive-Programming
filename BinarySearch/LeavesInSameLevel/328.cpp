/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool dfs(Tree* root,int currLevel, int &level)
{
    if(!root)
        return true;;
    if(!root->left && !root->right)  
    {
        if(level!=-1)
        {
            if(currLevel != level)
                return false;
            else 
                return true;    
        }
        else 
        {
            level = currLevel;
            return true;
        }
    }

    if(!dfs(root->left, currLevel+1, level))
        return false;
    if(!dfs(root->right, currLevel+1, level))
        return false;
    return true;    
             
}
bool solve(Tree* root) {
    int level = -1;
    return dfs(root, 0, level);
}
