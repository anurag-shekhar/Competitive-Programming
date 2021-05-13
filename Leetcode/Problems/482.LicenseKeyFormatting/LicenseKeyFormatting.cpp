/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LicenseKeyFormatting.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        
        unordered_map<char, char> m;
        
        for(char key = 'a', val = 'A'; key<='z';  key++,val++)
            m[key] = val;
        for(char key = 'A'; key<='Z'; key++)
            m[key] = key;
        for(char key = '0'; key<='9'; key++)
            m[key] = key;
        string res = "";
        int n = s.size();
        
        int putDash = 0;
        char ch;
        for(int i = n-1; i>=0 ; i--)
        {
            if(s[i]=='-')
                continue;
            ch = m[s[i]];
            if(putDash && putDash%k==0 )
            {
                res += "-";
                putDash = 0;
            }     
            putDash++;

            res += ch;
        }
        reverse(res.begin(), res.end());
        return res;
        
    }
};

