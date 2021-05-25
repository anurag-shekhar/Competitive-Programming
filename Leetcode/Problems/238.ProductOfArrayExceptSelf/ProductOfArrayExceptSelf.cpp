/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ProductOfArrayExceptSelf.cpp
 * Created on : Tue May 25 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        int n = nums.size();
        
        vector<int> prefix(n), suffix(n);
        
        
        for(int i = 0; i<n; i++)
        {
            prefix[i] = nums[i];
            suffix[n-1-i] = nums[n-1-i];
            
            if(i!=0)
            {
                prefix[i] *= prefix[i-1];
                suffix[n-i-1] *= suffix[n-i];
            }
        }
        
        vector<int> res(n);
        for(int i = 0; i<n; i++)
        {
            if(i==0)
                res[i] = suffix[i+1];
            else if(i==n-1)
                res[i] = prefix[i-1];
            else 
                res[i] = prefix[i-1]*suffix[i+1];
        }
        return res;
            
    }
};

/*
1   2  6  24
24 24 12   4
*/
