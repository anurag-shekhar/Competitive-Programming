/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumNumberOfVisiblePoints.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */

class Solution {
public:
    double pi = acos(-1.0);
    double getAngle(double num, double den)
    {
        return atan2(num,den)*180/pi ;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        
        vector<double> allAngles;
        
        int samePts = 0;
        for(auto a : points)
        {
            if(a == location)
                samePts++;
            else 
                allAngles.push_back(getAngle(a[1] - location[1], a[0]-location[0]));
        }
        
        sort(allAngles.begin(), allAngles.end());
        vector<double> setOfAngles = allAngles;
        for(double a : allAngles)
            setOfAngles.push_back(a+360);
    
        int left = 0, right = 0;
        int n = setOfAngles.size();
        int res= 0;
        while(right<n)
        {
            if(setOfAngles[right]-setOfAngles[left] <= angle)
            {
                res = max(res, right-left+1);
                right++;
            }
            else 
                left++;
        }
        return res+samePts;
    }
};
