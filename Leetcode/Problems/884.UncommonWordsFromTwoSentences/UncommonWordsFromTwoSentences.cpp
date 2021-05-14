/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : UncommonWordsFromTwoSentences.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        unordered_map<string, int> m;
        for(int i = 0; i<s1.size(); i++)
        {
            string build = "";
            while(i<s1.size() && s1[i]!=' ')
                build += s1[i++];
            
            m[build]++;
        }
        
        for(int i = 0; i<s2.size(); i++)
        {
            string build = "";
            while(i<s2.size() && s2[i]!=' ')
                build += s2[i++];
            m[build]++;
        }
        
        vector<string> res;
        for(pair<string,int> a : m)
            if(a.second==1)
                res.push_back(a.first);
        return res;
    }
};
