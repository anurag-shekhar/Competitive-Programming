/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumMovesToEqualArrayElementsII.cpp
 * Created on : Wed May 19 2021
 ****************************************************************
 */

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int midIdx = n/2;
        int mid = nums[midIdx];
        if(n%2==0)
        {
            mid += nums[midIdx-1];
            mid /=2;
        }   
        int res = 0;
        for(int a : nums)
            res += abs(mid-a);
        return res;
    }
};
/*

1 2 6 = 5

1 2 3 4 5 6 7 8 9 10
1 2 5 10 = 2 -> 1 + 3 + 8 = 12 
           3 -> 2+1+2+7 = 12
           4 -> 3+2+1+6 = 12
           5 -> 4 + 3 + 5 = 12 
           6 -> 1 + 4 + 5+ 4 


1 10 = 9
1 3 10 = 9
*/
