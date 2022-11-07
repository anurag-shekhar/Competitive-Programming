/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : Maximum69Number.cpp
 * Created on : Tue Nov 08 2022 
 ***************************************************************
 */

class Solution {
public:

    int stoi(string s, int n) {
        if(n == 0)
            return s[n] - '0';
        return (s[n] - '0') + 10*stoi(s, n-1);
    }
    int maximum69Number (int num) {

        string s = to_string(num);


        int l = 0, n = s.size();

        while( l<n && s[l] != '6') l++;
        if (l<n)
            s[l] = '9';
        return stoi(s, s.size()-1);
    }
};
