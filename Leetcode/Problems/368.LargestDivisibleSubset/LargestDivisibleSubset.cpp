/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmailcom
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LargestDivisibleSubset.cpp
 * Created on : Wed Jul 03 2024
 ****************************************************************
 */

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<pair<int,int> >  dp(n);
        pair<int,int> longestSubset;
        longestSubset = {0, 0};
        for(int i = 0; i<n; i++) {
            dp[i] = {1,-1};
            for(int j = 0; j<i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i].first < dp[j].first+1) {
                    dp[i].first = dp[j].first+1;
                    dp[i].second = j;
                }
            }
            if(longestSubset.first < dp[i].first) {
                longestSubset.first = dp[i].first;
                longestSubset.second = i;
            }
        }
        //cout<<longestSubset.first<<" "<<longestSubset.second<<endl;
        stack<int> s;
        int idx = longestSubset.second;
        while(idx != -1) {
            s.push(nums[idx]);
            idx = dp[idx].second;
        }
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
