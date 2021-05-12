/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : TruncateSentence.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    string truncateSentence(string s, int k) {
        
        string res = "";
        for(int i = 0; i<s.size() && k; i++)
        {
            string temp="";
            while(i<s.size() && isalpha(s[i]))
            {
                temp += s[i];
                i++;
            }
            res+= temp;
            if(temp.size()!=0)
                k--;
            if(k==0)
                break;
            res += s[i];
        }
        return res;
        
    }
};
