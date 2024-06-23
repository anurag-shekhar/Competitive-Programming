/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SerializeAndDeserializeBinaryTree_2.cpp
 * Created on : Sun Jun 23 2024
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
        if(root) {
            string num = to_string(root->val);
            string left = serialize(root->left);
            string right = serialize(root->right);
            string builder = num + "(" + left + ")(" + right +")";
            return builder;
        }
        return "N";
        
    }

    // Decodes your encoded data to tree.
    int stringToInt(string s) {
        int left = 0;
        int right = s.size()-1;
        bool isNegative = false;
        if(s[0] == '-') {
            isNegative = true;
            left++;
        }
        int num = 0;
        for(int i = left; i<= right; i++) {
            num = (num*10 + (s[i]-'0')); 
        }
        
        if(isNegative)
            num *= -1;
        return num;
        
    }
    TreeNode* deserialize(string data) {
        if(data[0]== 'N') 
            return NULL;
        string num = "";
        int idx = 0;
        while(data[idx] != '(') {
            num += data[idx++];
        }
        int number = stringToInt(num);
        TreeNode* root = new TreeNode(number);
        string left = "";
        idx++;
        int closeBracket = 0;
        while(1) {
            if(data[idx] == '(')
                closeBracket++;
            else if(data[idx] == ')')
                closeBracket--;
            if(closeBracket == -1)
                break;
            left += data[idx];
            idx++;
        }
        idx+=2;
        closeBracket = 0;
        string right = "";
        while(1) {
            if(data[idx] == '(')
                closeBracket++;
            else if(data[idx] == ')')
                closeBracket--;
            if(closeBracket == -1)
                break;
            right += data[idx];
            idx++;
        }
        root->left = deserialize(left);
        root->right = deserialize(right);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

/*
1(2(Null)(Null))(3(4(N)(N))(5(N)(N)))
*/
