/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : KthLargestElementInArray.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
                
        priority_queue<int, vector<int>, greater<int> > minHeap;
        
        for(int i = 0; i<k; i++)
            minHeap.push(nums[i]);
        
        for(int i = k; i<nums.size(); i++)
        {
            if(minHeap.top() < nums[i])
            {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};
