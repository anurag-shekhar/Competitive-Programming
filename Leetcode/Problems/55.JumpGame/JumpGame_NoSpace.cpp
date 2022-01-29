/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : JumpGame_NoSpace.cpp
 * Created on : Sat Jan 29 2022
 ****************************************************************
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        int highestReach = 0;
        int currPos = 0;
        while(currPos <= highestReach)
        {
            if(nums[currPos] + currPos > highestReach)
                highestReach = nums[currPos] + currPos;
            if(highestReach >= n-1)
                return true;
            currPos++;
        }
        return false;
    }
};