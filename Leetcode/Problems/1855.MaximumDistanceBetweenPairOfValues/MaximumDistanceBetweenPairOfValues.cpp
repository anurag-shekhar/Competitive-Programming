/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumDistanceBetweenPairOfValues.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        //Method 1 (2 Pointer)
        int n1 = nums1.size();
        int n2 = nums2.size();
        int res = 0;
        
        int i = 0, j =0;
        
        while(i<n1 && j<n2)
        {
            if(nums2[j] >= nums1[i])
            {
                res = max(j-i, res);
                j++;
            }
            else 
                i++;
        }
        return res;
        
        
        /* Method 2 (lower_bound)
        int n1 = nums1.size();
        int n2 = nums2.size();
        int res = 0;
        for(int i = 0; i<n2; i++)
        {
            auto itr = lower_bound(nums1.begin(), nums1.end(), nums2[i], greater<int>());
            if(itr != nums1.end())
                res = max(res, (int)(i-(itr-nums1.begin())));            
        }
        return res;
        */
    }
};
