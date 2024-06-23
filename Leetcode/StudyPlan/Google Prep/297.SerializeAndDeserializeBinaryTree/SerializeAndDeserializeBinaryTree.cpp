/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SerializeAndDeserializeBinaryTree.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "N";
        
        string l = serialize(root->left);
        string r = serialize(root->right);
        
        string hash = to_string(root->val) + "(" + l +")" + "(" + r + ")";
        return hash;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data=="N")
            return NULL;
        int i=0;
        string rootVal = "";
        int n = data.size();
        while(i<n && data[i] !='(')
            rootVal += data[i++];
        
        string leftVal = "";
        int openBracket = 0;
        while(i<n)
        {
            if(data[i] == '(')
            {
                openBracket++;
                if(openBracket > 1)
                    leftVal += data[i];
            }
            else if(data[i] == ')')
            {
                openBracket--;
                if(openBracket == 0)
                    break;
                leftVal += data[i];
            }
            else 
                leftVal += data[i];
            i++;
        }
        i++;
        string rightVal = "";
        openBracket = 0;
        while(i<n)
        {
            if(data[i] == '(')
            {
                openBracket++;
                if(openBracket > 1)
                    rightVal += data[i];
            }
            else if(data[i] == ')')
            {
                openBracket--;
                if(openBracket == 0)
                    break;
                rightVal += data[i];
            }
            else 
                rightVal += data[i];
            i++;
        }
        
        TreeNode* root = new TreeNode(stoi(rootVal));
        
        root->left = deserialize(leftVal);
        root->right = deserialize(rightVal);
        
        return root;   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
