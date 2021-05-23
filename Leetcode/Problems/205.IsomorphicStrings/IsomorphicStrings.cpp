/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : IsomorphicStrings.cpp
 * Created on : Sun May 23 2021
 ****************************************************************
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int sSize = s.size();
        int tSize = t.size();
        if(sSize!=tSize)
            return false;
        unordered_map<char, char> m;
        unordered_set<char> store_t;
        for(int i = 0; i<sSize; i++)
        {
            if(m.count(s[i])==0 )
            {
                m[s[i]] = t[i];
                s.insert(t[i]);
            }
            else 
            {
                if(m[s[i]]!=t[i])
                    return false;
            }
        }
        return true;
        
    }
};
