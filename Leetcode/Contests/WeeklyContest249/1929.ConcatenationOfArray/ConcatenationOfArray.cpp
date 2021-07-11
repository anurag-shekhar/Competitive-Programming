/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ConcatenationOfArray.cpp
 * Created on : Sun Jul 11 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0; i<n; i++)
        {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};
