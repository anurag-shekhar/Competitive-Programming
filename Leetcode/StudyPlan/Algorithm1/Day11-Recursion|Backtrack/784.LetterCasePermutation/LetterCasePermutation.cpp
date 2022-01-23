/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LetterCasePermutation.cpp
 * Created on : Sun Jan 23 2022
 ****************************************************************
 */

class Solution {
public:
    void backtrack(vector<string> &result, unordered_map<char, vector<char> > &m,  string s, int start, int n)
    {
        if(start == n)
        {
            result.push_back(s);
            return;
        }
        
        if(m.count(s[start]))
        {
            for(char ch : m[s[start]])
            {
                s[start] = ch;
                backtrack(result, m, s, start+1, n);
            }    
        }
        else 
            backtrack(result, m, s, start+1, n);
            
    }
    vector<string> letterCasePermutation(string s) {
        
        unordered_map<char, vector<char> > m;
        for(char ch1='a', ch2 ='A'; ch1<='z'; ch1++, ch2++)
        {
            m[ch1] = {ch1, ch2};
            m[ch2] = {ch1, ch2};
        }
        vector<string> result; 
        backtrack(result, m, s, 0, s.size());
        return result;
    }
};
