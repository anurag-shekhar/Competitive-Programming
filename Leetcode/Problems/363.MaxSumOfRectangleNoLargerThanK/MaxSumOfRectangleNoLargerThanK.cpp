/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaxSumOfRectangleNoLargerThanK.cpp
 * Created on : Sat Jul 03 2021
 ****************************************************************
 */

class Solution {
public:
    
    int maxSubarray(vector<int> nums, int k)
    {
        set<int> s;
        int sum = 0;
        int n = nums.size();
        s.insert(0);
        
        int res = INT_MIN;
        for(int i = 0; i<n; i++)
        {
            sum += nums[i];
            int presum = sum - k;
            auto itr = s.lower_bound(presum);
            
            if(itr!=s.end())
            {
                res = max(res, sum-*itr);
            }
            s.insert(sum);
        }
        return res;
    }
    // sum - presum <= k  -> sum - k <= presum;
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int res =INT_MIN;
        for(int i = 0; i<r; i++)
        {
            vector<int> prefix(c,0);
            for(int j = i; j<r; j++)
            {
                for(int k = 0; k<c; k++)
                {
                    prefix[k] += matrix[j][k];
                }
                
                res = max(res, maxSubarray(prefix, k));
                if(res == k)
                    return res;
            }
        }
        return res;
    }
};
                                      
/*
 1 2 3 4 5  -> 1 3 6 10 15
 1 2 3 4 5  -> 2 4
*/
 
