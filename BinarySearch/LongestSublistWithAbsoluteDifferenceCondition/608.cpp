/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 608.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

int solve(vector<int>& nums, int k) {
    
    int left = 0, right = 0;
    deque<int> maxdq, mindq;
    int n = nums.size();
    int res = 0;
    while(right<=n)
    {
        if(mindq.empty() || (nums[maxdq.front()] -  nums[mindq.front()]) <= k)
        {
            res = max(res, right-left);
            if(right==n)
                break;
            while(!mindq.empty() && nums[mindq.back()] > nums[right])
                mindq.pop_back();
            while(!maxdq.empty() && nums[maxdq.back()] < nums[right])
                maxdq.pop_back();    
            mindq.push_back(right);
            maxdq.push_back(right);

            right++;    
        }
        else 
        {
            if(mindq.front() <= left)
                mindq.pop_front();
            if(maxdq.front() <= left)
                maxdq.pop_front(); 
            left++;       
        }
    }
    return res;

}
