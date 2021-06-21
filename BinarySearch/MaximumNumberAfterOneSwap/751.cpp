/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 751.cpp
 * Created on : Tue Jun 22 2021
 ****************************************************************
 */

int stringToNum(string s)
{
    int num = 0;
    for(int i = 0; i<s.size(); i++)
    {
        num = num*10 + (s[i]-'0');
    }
    return num;
}
int solve(int n) {
    
    string s = to_string(n);
    unordered_map<int, int> m;
    for(int i = s.size()-1; i>=0; i--)
    {
        if(!m.count(s[i]-'0'))
            m[s[i]-'0'] = i;
    }

    for(int i = 0; i<s.size(); i++)
    {
        int val = s[i] - '0';
        for(int digit = 9; digit > val; digit--)
        {
            if(m.count(digit) && m[digit] > i)
            {
                swap(s[i], s[m[digit]]);
                return max(n,stringToNum(s));
            }
        }
    }
    return max(n,stringToNum(s));
}
