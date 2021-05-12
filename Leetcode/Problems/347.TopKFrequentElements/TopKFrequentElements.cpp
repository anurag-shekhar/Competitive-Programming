/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TopKFrequentElements.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> m;
        vector<int> res;
        int maxFreq = 0;
        for(int a : nums)
        {
            m[a]++;
            
            if(maxFreq < m[a])
                maxFreq = m[a];
        }

         vector<vector<int> > freqHash(maxFreq+1);
        
        for(pair<int,int> p : m)
            freqHash[p.second].push_back(p.first);
        
        for(int i = maxFreq; i>=0&&k>0 ; i--)
        {
            if(freqHash[i].size()!=0)
            {
                for(int j =0; j<freqHash[i].size(); j++)
                {    
                    res.push_back(freqHash[i][j]);
                    k--;
                } 
            }   
        }    
        return res;
            
        
        
    }
};
