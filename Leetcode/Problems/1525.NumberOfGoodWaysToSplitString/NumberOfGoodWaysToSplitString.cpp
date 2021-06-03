/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfGoodWaysToSplitString.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class Solution {
public:
    int numSplits(string s) {
        
        unordered_map<char, int> p,q;
        
        int n = s.size();
        p[s[0]]++;
        for(int i = 1; i<n; i++)
        {
            q[s[i]]++;
        }
        int count = 0;
        for(int i = 1; i<n; i++)
        {   
            if(p.size()==q.size())
                count++;
            
            p[s[i]]++;
            q[s[i]]--;
            if(q[s[i]]==0)
                q.erase(s[i]);
            
        }
        return count;
    }
};
