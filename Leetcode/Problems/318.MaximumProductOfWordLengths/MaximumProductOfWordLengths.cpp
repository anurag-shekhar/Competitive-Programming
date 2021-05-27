/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumProductOfWordLengths.cpp
 * Created on : Thu May 27 2021
 ****************************************************************
 */

class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        vector<unordered_set<int> > m(26);
        
        int n = words.size();
        for(int i = 0; i<n; i++)
        {
            for(char ch : words[i])
                m[ch-'a'].insert(i);
        }
        
        int res = 0;
        for(int i = 0; i<n-1; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                bool flag = true;
                for(int k = 0; k<26; k++)
                {
                    if(m[k].count(i) && m[k].count(j))
                    {
                        flag = false;
                        break;
                    }   
                    
                }
                if(flag)
                    res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};
