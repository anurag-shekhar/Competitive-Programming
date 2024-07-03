/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongestIncreasingSubsequence_optimised.cpp
 * Created on : Wed Jul 03 2024
 ****************************************************************
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> store;
        for(int i = 0; i < n; i++) {
            int idx = lower_bound(store.begin(), store.end(), nums[i]) - store.begin();
            if(idx == store.size())
                store.push_back(nums[i]);
            else 
                store[idx] = nums[i];
        }
        return store.size();
    }
};
