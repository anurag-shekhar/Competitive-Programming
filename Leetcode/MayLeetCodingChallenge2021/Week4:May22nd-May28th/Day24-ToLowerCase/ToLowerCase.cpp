/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ToLowerCase.cpp
 * Created on : Mon May 24 2021
 ****************************************************************
 */


class Solution {
public:
    string toLowerCase(string s) {
        
        unordered_map<int, char> m;
        
        for(char ch1 ='A', ch2 = 'a'; ch1<='Z'; ch1++, ch2++)
            m[ch1] = ch2;
        
        
        int n = s.size();
        for(int i =0 ; i<n; i++)
        {
            if(m.count(s[i]))
                s[i] = m[s[i]];
        }
        return s;
    }
};
