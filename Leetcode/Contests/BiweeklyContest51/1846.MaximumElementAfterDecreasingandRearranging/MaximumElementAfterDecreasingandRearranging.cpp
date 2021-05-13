/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumElementAfterDecreasingandRearranging.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        arr[0]=1;
        int prev = 1;
        for(int i = 1; i<n; i++)
        {
            arr[i] = min(prev+1,arr[i]);
            prev = arr[i];
        }
        
        return arr[n-1];
    }
};
