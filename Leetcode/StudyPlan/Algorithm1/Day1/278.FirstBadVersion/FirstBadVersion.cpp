/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FirstBadVersion.cpp
 * Created on : Fri Nov 05 2021
 ****************************************************************
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int low = 1; 
        int high = n;
        
        int res = n;
        while(low<=high)
        {
            int mid = (high-low)/2 + low;
            
            if(isBadVersion(mid))
            {
                res = mid;
                high = mid-1;
            }
            else 
                low = mid+1;
            
        }
        return res; 
        
    }
};