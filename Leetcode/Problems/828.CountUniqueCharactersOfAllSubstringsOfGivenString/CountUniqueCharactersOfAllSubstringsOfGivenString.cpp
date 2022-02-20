/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountUniqueCharactersOfAllSubstringsOfGivenString.cpp
 * Created on : Mon Feb 21 2022
 ****************************************************************
 */

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> lastOccur(26, 0);
        vector<int> contribution(26, 0);
        int res = 0;
        for(int i = 0; i<s.size(); i++)
        {
            int val = s[i] - 'A';
            int ans = 0;
            contribution[val] = i+1 - lastOccur[val];
            for(int i = 0; i<26; i++)
            {
                ans += contribution[i];        
            }
            res += ans;
            lastOccur[val] = i+1;
        }
        return res; 
        
    }
};