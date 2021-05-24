/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MajorityElementII.cpp
 * Created on : Mon May 24 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = -1;
        
        for(int a : nums)
        {
            if(candidate1==a && candidate2!=a)
                count1++;
            else if(candidate1!=a && candidate2==a)
                count2++;
            else if(count1==0)
            {
                candidate1 =a;
                count1 = 1;
            }
            else if(count2==0)
            {
                candidate2 =a;
                count2 = 1;
            }
            else 
            {
                count1--;
                count2--;
            }
        }
        int n = nums.size();
        count1=0, count2=0;
        for(int a : nums)
        {
            if(candidate1 == a) count1++;
            if(candidate2 == a) count2++;
        }
        vector<int> res;
        if(3*count1 > n)
            res.push_back(candidate1);
        if(3*count2 > n)
            res.push_back(candidate2);
        return res;
    }
};
