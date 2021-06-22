/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfMatchingSubsequences.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<set<int> > m(26);
        
        for(int i = 0; i<s.size(); i++)
        {
            m[s[i]-'a'].insert(i);
        }
        
        int res =0;
        for(int i = 0; i<words.size(); i++)
        {
            int idx = -1;
            for(int j = 0; j<words[i].size(); j++)
            {
                auto itr = m[words[i][j]-'a'].upper_bound(idx);
                if(itr == m[words[i][j]-'a'].end())
                {
                    res--;
                    break;
                }
                idx = *itr;
            }
            res++;
        }
        return res;
    }
};
