/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ConfusingNumber.cpp
 * Created on : Sat May 22 2021
 ****************************************************************
 */

class Solution {
public:
    bool confusingNumber(int n) {
        
        unordered_set<char> s;
        unordered_map<char,char> m;
        
        s.insert('2');
        s.insert('3');
        s.insert('4');
        s.insert('5');
        s.insert('7');
        
        m['0'] = '0';
        m['1'] = '1';
        m['6'] = '9';
        m['8'] = '8';
        m['9'] = '6';
        
        string res = "";
        string original = to_string(n);
        for(char c : original)
        {
            if(s.count(c))
                return false;
            res += m[c];
        }
        reverse(res.begin(), res.end());
        
        return res != original;
    }
};
