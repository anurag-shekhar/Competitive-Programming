/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RemoveOneElementToMakeTheArrayStrictlyIncreasing.cpp
 * Created on : Sun Jun 27 2021
 ****************************************************************
 */

class Solution {
public:
    bool checkIncre(vector<int>& nums)
    {
        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i-1] >= nums[i])
                return false;
        }
        return true;
    }
    bool canBeIncreasing(vector<int>& nums) {
        
        
        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i-1] >= nums[i])
            {
                vector<int> temp1, temp2;
                for(int j = 0; j<nums.size(); j++)
                {
                    if(j!=i)
                        temp1.push_back(nums[j]);
                    if(j!=(i-1))
                        temp2.push_back(nums[j]);
                }
                if(!checkIncre(temp1) && !checkIncre(temp2))
                    return false;
            }
        }
        return true;
    }
};
