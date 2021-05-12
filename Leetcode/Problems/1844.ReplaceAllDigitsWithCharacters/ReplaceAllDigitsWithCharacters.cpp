/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReplaceAllDigitsWithCharacters.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    char shift(char x, int c)
    {
        return (char)(x+c);
    }
    string replaceDigits(string s) {
        
        int i = 0;
        int n = s.size();
        
        while(i<n)
        {
            char x = s[i++];
            if(i==n)
                break;
            int c = s[i]-'0';
            s[i] = shift(x,c);
            i++;
        }
        return s;
    }
};
