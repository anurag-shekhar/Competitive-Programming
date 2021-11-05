/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SquaresOfSortedArray.cpp
 * Created on : Fri Nov 05 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        

        
        int n = nums.size();
        int leftPtr =-1, rightPtr = n;
        for(int i = 0; i<n; i++)
        {
            if(nums[i]>=0)
            {
                leftPtr = i-1;
                rightPtr = i;
                break;
            }
            leftPtr = i;
        }
        
        vector<int> res(n);
        
        for(int i = 0; i<n; i++)
        {
            if(leftPtr > -1 && rightPtr < n)
            {
                if(abs(nums[leftPtr]) < abs(nums[rightPtr]))
                {
                    res[i] = nums[leftPtr] * nums[leftPtr];
                    leftPtr--;
                }
                else 
                {
                    res[i] = nums[rightPtr] * nums[rightPtr];
                    rightPtr++;
                }
            }
            else if(leftPtr > -1)
            {
                res[i] = nums[leftPtr] * nums[leftPtr];
                leftPtr--;
            }
            else 
            {
                res[i] = nums[rightPtr] * nums[rightPtr];
                rightPtr++;
            }
                
        }
        return res;
        
        
        
    }
};
