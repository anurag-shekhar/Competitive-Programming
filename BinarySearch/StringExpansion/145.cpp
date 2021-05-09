/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 145.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

string solve(string s) {

    string res = "";
    int n = s.size();
    for(int i = 0; i<n; i++)
    {
        if(isdigit(s[i]))
        {
            string times = "";
            while(i<n && isdigit(s[i]))
            {
                times+=s[i];
                i++;
            }
            i++;
            string t = "";
            int count = 1;
            while(i<n)
            {
                if(s[i]=='(')
                    count++;
                if(s[i]==')')
                    count--;
                if(count!=0)
                    t+=s[i];
                else 
                    break;    
                i++;    
            }
            t = solve(t);
            int nTimes = stoi(times);

            while(nTimes--)
                res+=t;
        }
        else 
            res += s[i];
    }
    return res;
}
