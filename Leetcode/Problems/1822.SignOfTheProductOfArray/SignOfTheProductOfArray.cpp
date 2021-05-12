/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SignOfTheProductOfArray.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int neg = 0, pos = 0;
        
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i]==0)
                return 0;
            if(nums[i]<0)
                neg++;

        }
        if(neg%2)
            return -1;
        return 1;
        
    }
};
