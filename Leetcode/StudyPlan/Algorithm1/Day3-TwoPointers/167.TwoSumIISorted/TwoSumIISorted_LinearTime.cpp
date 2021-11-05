/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TwoSumIISorted_LinearTime.cpp
 * Created on : Fri Nov 05 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        int left = 0, right = n-1;
        
        while(left <= right)
        {
            if(numbers[left] + numbers[right] == target)
                return {left+1, right+1};
            else if(numbers[left] + numbers[right] < target)
                left++;
            else 
                right--;
        }
        return {left+1, right+1};
    }
};