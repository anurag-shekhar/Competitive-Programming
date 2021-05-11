/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NextClosestTime.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    void increaseTime(vector<int> &time)
    {
        //19:39
        //.   0
        time[3]++;
        time[2] += time[3]/10;
        time[1] += time[2]/6;
        if(time[0]==2)
        {
            time[0] += time[1]/4;
            time[1] %= 4;
        }
        else 
        {
            time[0] += time[1]/10;
            time[1] %= 10;
        }
        
        time[0] %= 3;
        time[2] %= 6;
        time[3] %= 10;
    }
    
    string convertTime(vector<int> &time)
    {
        string s = to_string(time[0]);
        s += to_string(time[1]);
        s += ":";
        s += to_string(time[2]);
        s += to_string(time[3]);
        return s;
    }
    bool isValid(unordered_set<int> &s, vector<int> &time)
    {
        if(s.count(time[0]) && s.count(time[1]) 
           && s.count(time[2]) && s.count(time[3]))
            return true;
        return false;
    }
    string nextClosestTime(string time) {
        
        vector<int> v_time(4);
        
        v_time[0] = time[0]-'0';
        v_time[1] = time[1]-'0';
        v_time[2] = time[3]-'0';
        v_time[3] = time[4]-'0';
        
        unordered_set<int> s;
        for(int a : v_time)
            s.insert(a);
        
        while(1)
        {
            increaseTime(v_time);
            if(isValid(s, v_time))
                return convertTime(v_time);
        }
        return "";
        
        
    }
};
