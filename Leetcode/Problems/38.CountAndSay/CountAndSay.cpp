/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountAndSay.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    string countAndSay(int n) {
    
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
};
