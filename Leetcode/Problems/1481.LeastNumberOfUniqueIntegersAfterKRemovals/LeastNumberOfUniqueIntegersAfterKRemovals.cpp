/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LeastNumberOfUniqueIntegersAfterKRemovals.cpp
 * Created on : Mon Feb 21 2022
 ****************************************************************
 */

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        
        for(int a : arr)
            m[a]++;
        
        vector<int> freq(arr.size()+1, 0);
        
        int remain = 0;
        for(auto p : m)
        {
            freq[p.second]++;
            remain++;
        }
        
        int i = 1;
        while(k>0 || remain > 0)
        {
            if(freq[i] > 0)
            {
                int val = k/i; 
                if(val >= freq[i])
                {
                    remain -= freq[i];
                    k -= freq[i]*i;
                }
                else 
                {
                    remain -= val;
                    return remain;
                }
            }
            i++;
        }
        return remain;
    }
};