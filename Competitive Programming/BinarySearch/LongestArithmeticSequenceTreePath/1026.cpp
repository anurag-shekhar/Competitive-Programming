/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
class node
{
    public:
    int val;
    node *left;
    node *right;
    node *parent;
    unordered_map<int,int> m;
    node(int v, node* p): val(v), parent(p), left(NULL), right(NULL){}
};

void compute(node* root, int &res)
{
    if(!root)
        return;
    node* prev = root->parent;
    
    //while(prev)
    if(prev)
    {
        int diff = root->val - prev->val;
        auto itr = prev->m.find(diff);
        if(itr == prev->m.end())
            root->m[diff] = max(2,root->m[diff]);
        else 
            root->m[diff] = max(root->m[diff], prev->m[diff]+1);  
        res = max(res , root->m[diff]);
        //prev = prev->parent;     
    }
    compute(root->left, res);
    compute(root->right, res);
}

node* create(Tree* root, node* prev)
{
    if(!root)
        return NULL;

    node* newRoot = new node(root->val, prev);
    newRoot->left = create(root->left, newRoot);
    newRoot->right = create(root->right, newRoot);
    return newRoot;
}


void dfs(Tree* root, Tree* prev, int diff,bool dflag, int &res, int count)
{
    if(!root)
        return;
    if(prev)
    {
        if(dflag)
        {
            if(diff != (root->val - prev->val))
            {
                diff = root->val - prev->val;
                count = 1;
            }
            res = max(count+1 ,res);
        } 
        else 
        {
            dflag = true;
            diff  = root->val - prev->val;
            res = max(count+1 ,res);
        }  
    }   
    else 
        dflag = false;        
    dfs(root->left, root, diff,dflag, res, count+1); 
    dfs(root->right, root, diff,dflag, res, count+1);
}
int solve(Tree* root) {
    
    if(!root)
        return 0;
    int res = 1;  
    dfs(root, NULL, 0, false, res, 0);
    /* //IF NON-CONTINOUS SEQUENCE INSTEAD OF CONTIGOUS SEQUENCE
    node* newRoot = create(root, NULL);
    compute(newRoot, res);
    */
    return res;
}
