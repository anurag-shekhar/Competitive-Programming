/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CuttingRibbons.cpp
 * Created on : Mon Mar 07 2022
 ****************************************************************
 */

class Solution {
public:
    
    bool isPossible(vector<int>& ribbons, int k, int len)
    {
        int count = 0;
        for(int r : ribbons)
        {
            count += r/len;
            if(count >= k)
                return true;
        }
        return false;
    }
    int maxLength(vector<int>& ribbons, int k) {
        
        //sort(ribbons.begin(), ribbons.end());
        int left = 1; 
        int right = *max_element(ribbons.begin(), ribbons.end());
        
        int res = 0;
        while(left <= right)
        {
            int mid = (left+right)/2;
            
            if(isPossible(ribbons, k, mid))
            {
                left = mid+1;
                res = max(res, mid);
            }
            else 
                right = mid-1;
        }
        return res;
    }
};
