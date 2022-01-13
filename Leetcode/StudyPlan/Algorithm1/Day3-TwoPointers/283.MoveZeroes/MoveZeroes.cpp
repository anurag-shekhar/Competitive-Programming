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
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int left = 0, right = numbers.size()-1;
        
        while(left < right)
        {
            int val = numbers[left] + numbers[right]; 
            if(numbers[left] + numbers[right] == target)
                return {left+1, right+1};
            else if(val < target)
                left++;
            else 
                right--;
        }
        return {};
    }
};