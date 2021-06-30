/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 117.cpp
 * Created on : Thu Jul 01 2021
 ****************************************************************
 */



vector<int> solve(vector<int>& nums) {
    
    deque<int> dq;
    int n = nums.size();
    for(int i = 0; i<n; i++)
    {
        if(nums[i] > 0)
            dq.push_back(nums[i]);
        else 
        {
            while(!dq.empty() && dq.back() > 0)
            {
                if(dq.back() >= abs(nums[i]))
                {
                    if(dq.back() == abs(nums[i]))
                        dq.pop_back();
                    nums[i] = 0;
                    break;  
                }
                else 
                    dq.pop_back();
            }
            if(nums[i]!=0)
                dq.push_back(nums[i]);
        }
    }

    vector<int> res;
    while(!dq.empty())
    {
        res.push_back(dq.front());
        dq.pop_front();
    }
    return res;
}
