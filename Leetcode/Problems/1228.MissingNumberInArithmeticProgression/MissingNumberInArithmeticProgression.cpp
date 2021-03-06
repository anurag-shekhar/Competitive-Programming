/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MissingNumberInArithmeticProgression.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int missingNumber(vector<int>& arr) {
            
        int diff = arr[1] - arr[0];
        int diff2 = arr[2] - arr[1];
        
        if(diff == 2*diff2)
            diff = diff2;
        int n = arr.size();
        for(int i = 0; i<n-1; i++)
        {
            if(arr[i]+diff != arr[i+1])
                return arr[i]+diff;
        }
        return arr[0];
            
    }
};
