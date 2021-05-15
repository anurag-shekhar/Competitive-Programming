/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SortingtheSentence.cpp
 * Created on : Sat May 15 2021
 ****************************************************************
 */

class Solution {
public:
    string sortSentence(string s) {
        map<int, string> m;
        
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            string temp = "";
            while(i<n && isalpha(s[i]))
            {
                temp += s[i];
                i++;
            }
            int idx = 0;
            while(i<n && isdigit(s[i]))
            {
                idx = idx*10 + (s[i]-'0');
                i++;
            }
            m[idx] = temp;
        }
        string res = "";
        for(pair<int,string> p: m)
            res += (p.second+" ");
        return res.substr(0,res.size()-1);
        
    }
};
