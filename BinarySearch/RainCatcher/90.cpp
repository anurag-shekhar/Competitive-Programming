/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 90.cpp
 * Created on : Sun Jun 06 2021
 ****************************************************************
 */

int solve(vector<int>& nums) {
    
    int n = nums.size();
    vector<int> leftMax(n,0);
    vector<int> rightMax(n,0);

    for(int i = 0; i<n; i++)
    {
        if(i==0)
        {
             leftMax[i] = nums[i];
             rightMax[n-i-1] = nums[n-i-1]; 
        }   
        else 
        {
            leftMax[i] = max(leftMax[i-1], nums[i]);
            rightMax[n-i-1] = max(rightMax[n-i], nums[n-i-1]); 
        }
    } 

    int water = 0;
    for(int i = 0; i<n; i++)
    {
        water += (min(leftMax[i], rightMax[i]) - nums[i]);
    }
    return water;
}


/*

2 5 2 0 5 8 8
 
2 5 5 5 
  |.    |
  |     |
  |.    |
| | |.  |
| | |   | 
*/
