/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ValidAnagram.cpp
 * Created on : Sat Jun 26 2021
 ****************************************************************
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        
        for(char c : s)
            m[c]++;
        for(char c : t)
        {
            m[c]--;
            if(m[c]==0)
                m.erase(c);
        }
        if(m.size() == 0)
            return true;
        return false;
    }
};
