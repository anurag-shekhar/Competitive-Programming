/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindGreatestCommonDivisorOfArray.cpp
 * Created on : Sun Aug 22 2021
 ****************************************************************
 */

class Solution {
public:
    
    int gcd(int a, int b)
    {
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        
        int min_ele = INT_MAX;
        int max_ele = INT_MIN;
        
        for(int a : nums)
        {
            min_ele = min(a, min_ele);
            max_ele = max(a, max_ele);
        }
        return gcd(min_ele, max_ele);
    }
};
