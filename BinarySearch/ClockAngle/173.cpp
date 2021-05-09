/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 173.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */


int solve(int hour, int minutes) {
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

/*
3hr = 180min = 10800s -> 90d => 120s -> 1d
15min = 900s -> 90d         => 10s -> 1d

12*60*60 + 22*60 
43200 + 1320 = 44520s = 371d

22*60 = 1320s = 132d
108/9 = 36/3 = 12

22 39
19 53
23 7
*/
