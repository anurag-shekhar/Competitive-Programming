/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 432.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

void incrementTimer(vector<int> &timer)
{
    timer[3]++;
    timer[2] += timer[3]/10;
    timer[1] += timer[2]/6;
    if(timer[0]==2)
    {
        timer[0] += timer[1]/4;
        timer[1] %= 4;
    }    
    else
    {
        timer[0] += timer[1]/10;
        timer[1] %= 10;
    }
    timer[2] %= 6;
    timer[3] %= 10;
    timer[0] %= 3; 
}

bool isValid(unordered_set<int> &check, vector<int> &timer)
{
    for(int i = 0; i<4; i++)
    {
        if(check.find(timer[i])==check.end())
            return false;
    }
    return true;
}
string solve(string s) {
    
    vector<int> timer(4);
    timer[0] = s[0] - '0';
    timer[1] = s[1] - '0';
    timer[2] = s[3] - '0';
    timer[3] = s[4] - '0';

    unordered_set<int> check;
    check.insert(timer[0]);
    check.insert(timer[1]);
    check.insert(timer[2]);
    check.insert(timer[3]);

    while(1)
    {
        incrementTimer(timer);
        if(isValid(check, timer))
            return to_string(timer[0]) + to_string(timer[1]) + ":" + to_string(timer[2]) + to_string(timer[3]);    
    }
    return "";
}
