/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaxNumberOfKSumPairs.cpp
 * Created on : Sun Jan 09 2022
 ****************************************************************
 */

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        int n = nums.size();
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            int val = k - nums[i];
            if(m.find(val) != m.end())
            {
                m[val]--;
                count++;
                if(m[val] == 0)
                    m.erase(k-nums[i]);
            }
            else 
                m[nums[i]]++;
        }
        return count;
    }
};
