/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ReverseStringII.cpp
 * Created on : Fri May 14 2021
 ****************************************************************
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        
        string res = "";
        string build = "";
        int j = 0;
        for(int i =0; i<s.size(); i++)
        {
            
            while( i<s.size() && (i+1)%k)
            {
                build += s[i];
                i++;
            }
            build += s[i];
            
            if(j%2==0)
                reverse(build.begin(), build.end());
            j++;
            
            res += build;
            build = "";
        }
        string res2 = "";
        
        for(int i = 0; i<res.size(); i++)
        { 
            if(res[i]=='\x00')
               continue;
            else 
               res2 += res[i];
         }
        return res2;
    }
};
