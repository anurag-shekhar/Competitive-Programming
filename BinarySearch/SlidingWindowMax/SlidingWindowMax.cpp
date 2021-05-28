/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SlidingWindowMax.cpp
 * Created on : Fri May 28 2021
 ****************************************************************
 */

vector<int> solve(vector<int>& nums, int k) {
    deque<int> dq;

    int idx;
    int n = nums.size();
    for( idx= 0; idx<k-1 && idx<n; idx++)
    {
        while(!dq.empty() && nums[dq.back()] < nums[idx])
            dq.pop_back();
        dq.push_back(idx);
    }
    vector<int> res;
    while(idx<n)
    {
        while(!dq.empty() && nums[dq.back()] < nums[idx])
            dq.pop_back();
        dq.push_back(idx);

        while(dq.front() < idx-k+1)
            dq.pop_front();
        res.push_back(nums[dq.front()]);
        idx++;
    }
    return res;

}
