/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MajorityElement.cpp
 * Created on : Mon May 24 2021
 ****************************************************************
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int candidate = 0;
        
        int n = nums.size();
        for(int i=0; i<nums.size(); i++) //moore voting algo
        {
            if(count==0)
            {
                candidate = nums[i];
                count=1;
            }
            else
            {
                if(candidate==nums[i])
                    count++;
                else 
                    count--;
            }
        }
        count = 0;
        for(int a : nums) //correctness
            if(candidate==a)
                count++;
        
        if(2*count > n)
            return candidate;
        return -1;
        
        
    }
};
