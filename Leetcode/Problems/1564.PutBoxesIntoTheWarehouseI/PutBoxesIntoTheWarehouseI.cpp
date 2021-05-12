/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PutBoxesIntoTheWarehouseI.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        deque<int> dq;
        sort(boxes.begin(), boxes.end());
        int n = warehouse.size();
        for(int i = n-1; i>=0 ; i--)
        {
            while(!dq.empty() && warehouse[dq.back()] > warehouse[i])
                dq.pop_back();
            dq.push_back(i);
        }
        
        int count = 0;
        int left = 0;
        for(int i = n-1; i>=0; i--)
        {
            //cout<<dq.front()<<endl;
            if(boxes[left] <= warehouse[dq.front()])
            {
                left++;
                count++;
            }
            if(i==dq.front())
                dq.pop_front();
            if(dq.empty() || left == boxes.size())
                return count;
        }
        return count;
    }
};
