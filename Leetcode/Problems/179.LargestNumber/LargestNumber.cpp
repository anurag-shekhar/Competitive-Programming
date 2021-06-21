/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LargestNumber.cpp
 * Created on : Tue Jun 22 2021
 ****************************************************************
 */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                string A = to_string(nums[i]) + to_string(nums[j]);
                string B = to_string(nums[j]) + to_string(nums[i]);
                
                if(B > A)
                    swap(nums[i], nums[j]);
            }
        }
        if(nums[0] == 0)
            return "0";
        string res = "";
        for(int i =0 ; i<n; i++)
        {
            res += to_string(nums[i]);
        }
        return res;
    }
};
