/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 3Sum.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int> > res;
        //unordered_set<int> s;
        set<vector<int> > resSet;
        
        if(n < 3)
            return res;
        sort(nums.begin(),nums.end());
        // for(int a : nums)
        //     s.insert(a);
        
        for(int i = 0;i < n-2; i++)
        {
            for(int j = i+1; j<n-1; j++)
            {
                int val = -1*(nums[i] + nums[j]);
                //auto k = s.find(-1*val);
                if(binary_search(nums.begin()+j+1,nums.end(), val))
                {
                    vector<int> v = {nums[i],nums[j],val};
                    //sort(v.begin(), v.end());
                    resSet.insert(v);
                }
            }
        }
        for(vector<int> v : resSet)
            res.push_back(v);
        return res;
    }
};
