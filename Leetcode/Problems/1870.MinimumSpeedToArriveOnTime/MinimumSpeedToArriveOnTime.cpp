/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumSpeedToArriveOnTime.cpp
 * Created on : Sun May 23 2021
 ****************************************************************
 */

class Solution {
public:
    bool checkSpeed(vector<int>& dist, double hour, int mid)
    {
        double sum = 0;
        
        for(int i = 0; i<dist.size(); i++)
        {
            double a = (double)dist[i]/(double)mid;
            if((a+sum) > hour)
                return false;
            sum += ceil(a);
        }
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1; 
        int high = 10000000;
        
        int res = high;
        bool flag = true;
        while(low<=high)
        {
            int mid = (high-low)/2 + low;
            
            if(checkSpeed(dist, hour, mid))
            {
                flag = false;
                res = mid;
                high = mid-1;
            }
            else 
                low = mid+1;
            
        }
        if(flag)
            return -1;
        return res;
        
    }
};
