/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 265.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

string solve(int n) {
    
    string s = "1";

    while(n>1)
    {
        string temp = "";
        for(int i = 0; i<s.size(); i++)
        {
            char ch = s[i];
            int start = i;
            while(i<s.size() && ch == s[i])
                i++;
            i--;    
            temp += (to_string(i-start+1) + s[i]);
        }
        s = temp;
        n--;
    }
    return s;
}
