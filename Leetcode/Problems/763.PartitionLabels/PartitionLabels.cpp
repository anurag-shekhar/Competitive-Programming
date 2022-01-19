/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PartitionLabels.cpp
 * Created on : Wed Jan 19 2022
 ****************************************************************
 */

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char, int> lastIdx;
        vector<int> result;
        
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            lastIdx[s[i]] = i;
        }
        
        int i = 0;
        while(i<n)
        {
            int end = lastIdx[s[i]];
            
            int j = i+1;
            while(j <= end) {
                end = max(end, lastIdx[s[j++]]);
            }
            result.push_back(j-i);
            i = j;
        }
        return result;
        
        
        
    }
};
