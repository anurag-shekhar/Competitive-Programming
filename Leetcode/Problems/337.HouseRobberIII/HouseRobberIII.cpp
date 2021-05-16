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
    
    //{withRobbery, withoutRobbery}
    vector<int> solve(TreeNode* root)
    {
        if(!root)
            return {0,0};
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        
        int temp = max(max(l[0]+r[1], l[1]+r[0]), max(l[0]+r[0], l[1] + r[1]));
        return {root->val + l[1] + r[1], temp};
    }
    int rob(TreeNode* root) {
        
        vector<int> res = solve(root);
        return max(res[0], res[1]);
    }
};
