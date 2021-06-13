/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : KokoEatingBananas.cpp
 * Created on : Sun Jun 13 2021
 ****************************************************************
 */

class Solution {
public:
    bool canSheEat(vector<int> &piles, int h, int k)
    {
        int hours = 0;
        int n = piles.size();
        for(int i = 0; i<n; i++)
        {
            hours += piles[i]/k;
            if(piles[i]%k!=0)
                hours += 1;
            if(hours > h)
                return false;
        }
        return true;     
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        int res = high;
        while(low<=high)
        {
            int mid = (high-low)/2 + low;
            
            if(canSheEat(piles, h, mid))
            {
                res=mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return res;
    }
};
