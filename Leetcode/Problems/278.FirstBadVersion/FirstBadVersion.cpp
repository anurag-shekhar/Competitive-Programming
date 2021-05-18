/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FirstBadVersion.cpp
 * Created on : Tue May 18 2021
 ****************************************************************
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int low = 1, high = n;
        
        int badVersion = n;
        while(low<=high)
        {
            int mid = (high-low)/2 + low;
            if(isBadVersion(mid))
            {
                badVersion = mid;
                high = mid-1;
            }
            else 
                low = mid+1;
        }
        return badVersion;
        
    }
};
