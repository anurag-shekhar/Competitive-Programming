/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MoveZeroes.cpp
 * Created on : Fri Jan 14 2022
 ****************************************************************
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int lastInsertedPtr = -1;
        int ptr = 0;
        
        int n  = nums.size();
        while( ptr < n)
        {
            if(nums[ptr] != 0)
                nums[++lastInsertedPtr] = nums[ptr];
            if(lastInsertedPtr != ptr)
                nums[ptr] = 0;
            ptr++;
        }
    }
};