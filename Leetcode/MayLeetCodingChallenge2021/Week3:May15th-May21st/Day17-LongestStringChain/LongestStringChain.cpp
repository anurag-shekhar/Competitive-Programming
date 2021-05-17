/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestStringChain.cpp
 * Created on : Mon May 17 2021
 ****************************************************************
 */

class Solution {
public:
    int getLongestChain(unordered_map<string, int> &m, string s)
    {
        if(!m.count(s))
            return 0;
        if(m[s]!=-1)
            return m[s];
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            string temp = s.substr(0,i);
            if(i+1<n)
                temp += s.substr(i+1);
            m[s] = max(m[s],1+getLongestChain(m,temp)); 
        }
        
        return m[s];
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> m;
        
        for(string a : words)
            m[a] = -1;
        
        int res = 0;
        for(string a : words)
        {
            res = max(res, getLongestChain(m,a));
        }
        return res;
    }
};
