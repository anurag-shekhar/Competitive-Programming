/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindAndReplacePattern.cpp
 * Created on : Sat May 22 2021
 ****************************************************************
 */

class Solution {
public:
    string vanillaPattern(string s)
    {
        char ch = 'a';
        unordered_map<char,char> m;
        string res = "";
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            if(!m.count(s[i]))
                m[s[i]] = ch++;
            res+=m[s[i]];
        }
        return res;
    }
    
    bool findPattern(string &A, string &B)
    {
        
        return vanillaPattern(A)==B;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        pattern = vanillaPattern(pattern);
        for(string w : words)
            if(findPattern(w , pattern))
                res.push_back(w);
        
        return res;
    }
};
