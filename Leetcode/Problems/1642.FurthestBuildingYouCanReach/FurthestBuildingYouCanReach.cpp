/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FurthestBuildingYouCanReach.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders ) {
        
        priority_queue<int> maxHeap;
        int sum = 0;
        int n = heights.size();
        int i = 0;
        for(i = 0; i<n-1; i++)
        {
            if(heights[i+1] <= heights[i])
                continue;
            else 
            {
                int diff = heights[i+1] - heights[i];
                maxHeap.push(diff);
                sum += diff;
                if(sum > bricks)
                {
                    if(ladders==0)
                        break;
                    else 
                    {
                        sum -= maxHeap.top();
                        ladders--;
                        maxHeap.pop();
                    }
                }
            }
        }
        return i;
    }
};
