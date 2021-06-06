/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestConsecutiveSequence.cpp
 * Created on : Sun Jun 06 2021
 ****************************************************************
 */ 
    
class Solution {
public:
    unordered_map<int, int> m;
    int previousElementLength(int val)
    {
        if(m.count(val))
        {
            if(m[val] > 0)
                return m[val];
            return m[val] = 1+previousElementLength(val-1);
        }
        return 0;
    }
    int longestConsecutive(vector<int>& nums) {
        m.clear();
        
        for(int a : nums)
            m[a] = 0;
        
        int res = 0;
        for(int a : nums)
        {
            res = max(res, previousElementLength(a));
        }
        return res;
        
        
    }
};
