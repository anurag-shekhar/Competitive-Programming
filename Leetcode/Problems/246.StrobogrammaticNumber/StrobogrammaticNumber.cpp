/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : StrobogrammaticNumber.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m;
        m['0'] = '0';
        m['1'] = '1';
        m['8'] = '8';
        m['6'] = '9';
        m['9'] = '6';
        string s = num;
        for(int i = 0; i<num.size(); i++)
        {
            if(m.count(num[i]))
                num[i] = m[num[i]];
            else 
                return false;
        }
        reverse(num.begin(), num.end());
        return num == s;
    }
};
