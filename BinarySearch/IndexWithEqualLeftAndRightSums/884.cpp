/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 884.cpp
 * Created on : Sun Jun 06 2021
 ****************************************************************
 */

int solve(vector<int>& nums) {
    int n = nums.size();
    for(int i = 1; i<n; i++)
    {
        nums[i] += nums[i-1];
    }

    for(int i = 0; i<n; i++)
    {
        int leftSum = 0;
        int rightSum = 0;

        if(i>0)
            leftSum = nums[i-1];
        if(i<n-1)
            rightSum = nums[n-1]-nums[i];

        if(rightSum == leftSum)
            return i;        
    }
    return -1;
}
