/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 1025.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

vector<int> solve(vector<int>& nums) {
    vector<int> ans;
    stack<int> idxStack;

    int n = nums.size();
    if(n==0 || n==1)
        return {};
    
    idxStack.push(0);
    int prev = nums[0];
    
    int check = nums[0];
    int k;
    for(k = 1; k<n; k++)
    {
        if(check != nums[k])
            break;
    }
    if(k==n)
        return {};
    
    for(int i = 1; i<n; i++)
    {
        if(!idxStack.empty())
        {
            if(nums[idxStack.top()]==nums[i])
                idxStack.push(i);
            else if(nums[idxStack.top()] > nums[i])
            {
                while(!idxStack.empty() && nums[idxStack.top()] > nums[i])
                {
                    ans.push_back(idxStack.top());
                    idxStack.pop();
                }
            } 
            else
            {
                while(!idxStack.empty() && nums[idxStack.top()] < nums[i])
                    idxStack.pop();
                idxStack.push(i);
            } 
        }
        else 
        {
            if(prev < nums[i])
                idxStack.push(i);   
        }
        prev = nums[i];   
    }
    while(!idxStack.empty())
    {
        ans.push_back(idxStack.top());
        idxStack.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
