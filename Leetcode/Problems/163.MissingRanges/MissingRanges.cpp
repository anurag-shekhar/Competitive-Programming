/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MissingRanges.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        vector<string> res;
        nums.push_back(upper+1);
        int n = nums.size();
        lower--;
        for(int i = 0; i<n; i++)
        {
            upper = nums[i];
            int left,right;
            if(lower < upper)
            {
                left = lower+1;
                right = upper-1;
                if(left==right)
                    res.push_back(to_string(left));
                else if(left<right)
                    res.push_back(to_string(left) + "->" + to_string(right));
            } 
            lower = nums[i];
        }
        return res;
    }
};
