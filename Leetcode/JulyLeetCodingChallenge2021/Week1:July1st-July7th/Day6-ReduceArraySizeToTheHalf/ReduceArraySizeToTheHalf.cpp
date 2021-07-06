/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReduceArraySizeToTheHalf.cpp
 * Created on : Tue Jul 06 2021
 ****************************************************************
 */

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int n = arr.size();
        
        unordered_map<int, int> m;
        for(int a : arr)
            m[a]++;
            
        priority_queue<int> maxHeap;
        
        for(auto p : m)
        {
            maxHeap.push(p.second);
        }
        
        int size = 0;
        int res = 0;
        while(size < n/2)
        {
            size += maxHeap.top();
            maxHeap.pop();
            res++;
        }
        return res;
        
    }
};
