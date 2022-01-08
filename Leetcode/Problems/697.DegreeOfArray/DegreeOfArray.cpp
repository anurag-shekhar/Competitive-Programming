/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DegreeOfArray.cpp
 * Created on : Sat Jan 08 2022
 ****************************************************************
 */

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int, vector<int> > m;
        int n = nums.size();
        
        int maxFreq = 0;
        for(int i = 0; i<n; i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                m[nums[i]][0]++;
                m[nums[i]][2] = i;
            }
            else 
            {
                m[nums[i]].push_back(1);
                m[nums[i]].push_back(i);
                m[nums[i]].push_back(i);
            }
                
            maxFreq = max(maxFreq, m[nums[i]][0]);
        }
        
        int windowSize = INT_MAX;
        
        for(pair<int, vector<int> > p : m)
        {
            if(p.second[0] == maxFreq)
            {
                windowSize = min(windowSize, p.second[2] - p.second[1]+1);
            }
        }
        return windowSize;
            
        
    }
};
