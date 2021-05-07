/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevel = -1;
    void preorder(queue<pair<int,int> > &q,TreeNode* root,int level)
    {
        if(!root)
            return;
        maxLevel = max(maxLevel, level);
        q.push({root->val,level});
        preorder(q,root->left,level+1);
        preorder(q,root->right,level+1);
         
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
            
        queue<pair<int,int> > q;
        preorder(q,root,0);
        
        vector<vector<int> > res(maxLevel+1);
        
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            res[p.second].push_back(p.first);
        }
        return res;
        
        
        
    }
};
