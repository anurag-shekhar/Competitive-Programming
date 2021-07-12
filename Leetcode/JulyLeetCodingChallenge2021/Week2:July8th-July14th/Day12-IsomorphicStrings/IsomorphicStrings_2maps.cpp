/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : IsomorphicStrings_2maps.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(t.size() != s.size())
            return false;
        unordered_map<char, char> ts, st;
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            if(!ts.count(t[i]) && !st.count(s[i]))
            {
                ts[t[i]] = s[i];
                st[s[i]] = t[i];
            }
            else if(ts[t[i]]!=s[i] || st[s[i]]!= t[i])
            {
                return false;
            }
            s[i] = t[i];
        }
        return true;
    }
};
