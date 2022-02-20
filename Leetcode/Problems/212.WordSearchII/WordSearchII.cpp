/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : WordSearchII.cpp
 * Created on : Sun Feb 20 2022
 ****************************************************************
 */

class Solution {
public:
    
    class trie
    {
        public:
        vector<trie*> child;
        string word;
        
        trie()
        {
            child = vector<trie*> (26, NULL);
            word = "";
        }
    };
    
    trie* build(trie* root, vector<string>& words)
    {
        for(string s : words)
        {
            trie* node = root;
            for(char c : s)
            {
                if(node->child[c-'a'] == NULL)
                    node->child[c-'a'] = new trie();
                node = node->child[c-'a'];
            }
            node->word = s;
        }
        return root;
    }
    void backtrack(vector<vector<char>>& board, trie* root, int x, int y, int r, int c, vector<string> &res)
    {
        char ch = board[x][y];
        
        if(ch == '#' || root->child[ch-'a'] == NULL)
            return;
        root = root->child[ch-'a'];
        if(root->word!= "")
        {
            res.push_back(root->word);
            root->word = "";
        }
        board[x][y] = '#';
        if(x > 0)backtrack(board, root, x-1, y, r,c,res);
        if(y > 0)backtrack(board, root, x, y-1, r,c,res);
        if(x < r-1)backtrack(board, root, x+1, y, r,c,res);
        if(y < c-1)backtrack(board, root, x, y+1, r,c,res);
        board[x][y] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        trie* root = new trie();
        root = build(root, words);
        
        vector<string> res;
        int r = board.size();
        int c = board[0].size();
        for(int i = 0; i<r; i++)  
        {
            for(int j = 0; j<c; j++)
            {
                trie* temp = root;
                backtrack(board, temp, i, j, r, c, res);
            }
        }
        return res;
    }
};