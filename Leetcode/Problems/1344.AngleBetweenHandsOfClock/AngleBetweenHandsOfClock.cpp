/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AngleBetweenHandsOfClock.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        hour %= 12;
        double hourDegree = (hour*30.0 + minutes*0.5);
        double minDegree = (minutes*6);
        //cout<<round(hourDegree)<<" "<<minDegree<<endl;
        double angleDiff = (abs(hourDegree-minDegree));
        //cout<<angleDiff<<endl;
        if(angleDiff > 180)
            return 360-angleDiff;
        return angleDiff;
    }
};
