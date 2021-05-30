/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SlidingWindowMedian.cpp
 * Created on : Sun May 30 2021
 ****************************************************************
 */

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        multiset<double> s;
        vector<double> res;
        int n = nums.size();        
        int idx = 0;
        
        while(idx<k) s.insert(nums[idx++]); //inserting first k elements 
        
        auto mid = next(s.begin(), k/2);  // mid of multiset
        
        while(idx<=n)
        {
            double median = (*mid + *prev(mid, 1 - k%2))/2.0;
            res.push_back(median);
            
            if(idx==n)
                return res;
            
            s.insert(nums[idx]);
            
            if(nums[idx] < *mid)
                mid--;
            
            if(nums[idx-k] <= *mid)
                mid++;
            
            if(s.count(nums[idx-k]))
                s.erase(s.find(nums[idx-k]));
            
            idx++;
        }
        return res;
    }
};
