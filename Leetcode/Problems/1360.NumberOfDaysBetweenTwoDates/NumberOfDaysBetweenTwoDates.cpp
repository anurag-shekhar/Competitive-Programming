/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfDaysBetweenTwoDates.cpp
 * Created on : Sat May 15 2021
 ****************************************************************
 */

class Solution {
public:
    unordered_map<int,int> m;
    bool isLeapYear(int y)
    {
        if(y%400 ==0 )
            return true;
        else if(y%100 ==0)
            return false;
        else if(y%4 == 0)
            return true;
        else 
            return false;
    }
    int countDaysFromStarting(vector<int> &d)
    {
        int days = 0;
        for(int i = 1971; i<d[0]; i++)
        {
            days += 365;
            if(i%4 == 0 && isLeapYear(i))
                days += 1;
        }
        
        for(int i = 1; i<d[1]; i++)
        {
            days += m[i];
            if(i==2 && isLeapYear(d[0]))
                days += 1;
        }
        
        days += d[2];
        return days;
    }
    
    int daysBetweenDates(string date1, string date2) {
        
        vector<int> d1,d2;
        
        m[1] = 31;
        m[2] = 28;
        m[3] = 31;
        m[4] = 30;
        m[5] = 31;
        m[6] = 30;
        m[7] = 31;
        m[8] = 31;
        m[9] = 30;
        m[10] = 31;
        m[11] = 30;
        m[12] = 31;
        
        d1.push_back(stoi(date1.substr(0,4)));
        d1.push_back(stoi(date1.substr(5,2)));
        d1.push_back(stoi(date1.substr(8,2)));
        
        d2.push_back(stoi(date2.substr(0,4)));
        d2.push_back(stoi(date2.substr(5,2)));
        d2.push_back(stoi(date2.substr(8,2)));
    
        int days = abs(countDaysFromStarting(d1) - countDaysFromStarting(d2));
        return days;
        
    }
};

/*
2019-06-29
0123456789
*/

