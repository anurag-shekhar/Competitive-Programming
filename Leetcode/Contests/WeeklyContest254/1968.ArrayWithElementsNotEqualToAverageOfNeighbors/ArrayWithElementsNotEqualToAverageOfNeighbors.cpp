/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ArrayWithElementsNotEqualToAverageOfNeighbors.cpp
 * Created on : Sun Aug 15 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int> > minHeap;
        
        
        int left = 0, right = nums.size()-1;
        for(int a : nums)
        {
            maxHeap.push(a);
            minHeap.push(a);
        }
            
        
        bool flag = true;
        while(left <= right)
        { 
            if(flag)
            {
                int val = minHeap.top();
                minHeap.pop();
                nums[left] = val;
                left++;
                flag = false;
            }
            else 
            {
                int val = maxHeap.top();
                maxHeap.pop();
                nums[left] = val;
                left++;
                flag = true;
            }
        }
        return nums;
    }
};
