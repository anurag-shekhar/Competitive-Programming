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
