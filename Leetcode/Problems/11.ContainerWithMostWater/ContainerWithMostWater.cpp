/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ContainerWithMostWater.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */


class Solution {
public:
    int maxArea(vector<int>& height) {
        
        /*
        0 1 2 3 4 5 6 7 8
        1,8,6,2,5,4,8,3,7
        */
        
        int n = height.size();
        int l = 0, r = n-1;
        int res = INT_MIN;
        
        while(l<r)
        {
            res = max(res,min(height[l],height[r])*(r-l));
            
            if(height[l] < height[r])
                l++;
            else 
                r--;
        }
        return res;
    }
};
