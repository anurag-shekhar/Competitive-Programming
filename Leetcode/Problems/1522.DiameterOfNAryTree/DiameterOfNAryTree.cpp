/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DiameterOfNAryTree.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public: 
    
    int longestPath(Node* root, int &res)
    {
        if(!root)
            return 0;
        int secondMaxChild = 0;
        int maxChild = 0;
        
        
        for(Node* i : root->children)
        {
            int a = longestPath(i,res);
            if(maxChild < a)
            {
                secondMaxChild = maxChild;
                maxChild = a;
            }
            else if(secondMaxChild < a)
                secondMaxChild = a;
        }
       
        int temp = 1+maxChild;
        
        res = max(res, temp + secondMaxChild);
        return temp;
        
    }
    int diameter(Node* root) {
        
        int res = 0;
        longestPath(root, res);
        return res-1;
        
    }
};
