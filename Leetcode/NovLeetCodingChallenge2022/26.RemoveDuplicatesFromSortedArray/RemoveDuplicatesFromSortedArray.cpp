/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : RemoveDuplicatesFromSortedArray.cpp
 * Created on : Fri Nov 11 2022 
 ***************************************************************
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        int idx = 0, prevIdx = 0;
        while(idx < n) {
            if(nums[idx] != nums[prevIdx]) {
                prevIdx++;
                nums[prevIdx] = nums[idx]; 
            } 
            idx++;
        }
        return prevIdx+1;
    }
};