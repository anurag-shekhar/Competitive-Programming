/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : KthSmallestElementInSortedMatrix.cpp
 * Created on : Thu Jul 08 2021
 ****************************************************************
 */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int> maxHeap;
        
        for(auto v : matrix)
        {
            for(int a : v)
            {
                if(maxHeap.size() == k)
                {
                    if(maxHeap.top() > a)
                    { 
                        maxHeap.pop();    
                        maxHeap.push(a);
                    }
                }
                else 
                    maxHeap.push(a);
            }
        }
        return maxHeap.top();
    }
};
