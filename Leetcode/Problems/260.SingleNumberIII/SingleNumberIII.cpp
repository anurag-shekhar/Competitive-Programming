/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SingleNumberIII.cpp
 * Created on : Sun Jun 20 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int res = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            res ^= nums[i];
        }
        
        int bit = 0;
        for(bit = 0; bit<32; bit++)
        {
            if(((res>>bit) & 1) ==1)
                break;
        }
        int group0 = 0;
        int group1 = 0;
        
        for(int i = 0; i<nums.size(); i++)
        {
            if(((nums[i]>>bit) & 1) ==1)
                group1 ^= nums[i];
            else 
                group0 ^= nums[i];
        }
        return {group0, group1};   
    }
};
