/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : JumpGameII.cpp
 * Created on : Sat Jan 29 2022
 ****************************************************************
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int highestReach = 0;
        int currPos = 0;
        int currJumpEnd = 0;
        int count = 0;
        while(currPos <= highestReach)
        {
            if(currPos == n-1)
                return count;
            if(nums[currPos] + currPos > highestReach)
                highestReach = nums[currPos] + currPos;
            if(currPos == currJumpEnd)
            {
                count++;
                currJumpEnd = highestReach;
            }
            currPos++;
        }
        return count;
    }
};