/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MoveZeroes.cpp
 * Created on : Fri Nov 05 2021
 ****************************************************************
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        
        int j = 0;
        for(int i = 0; i<n; i++)
        {
            if(nums[i] == 0)
                continue;
            else
            {
                //nums[j] = nums[i]; //METHOD 1 
                swap(nums[j], nums[i]); //METHOD 2 with minimum Number of Operatons
                j++;
            }
        }
        // for(; j<n; j++)  //For Method 1
        //     nums[j] = 0;
    }
};
