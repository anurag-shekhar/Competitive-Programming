/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : InterleavingString.cpp
 * Created on : Thu Jun 03 2021
 ****************************************************************
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        
        if((s1.size() + s2.size()) != s3.size())
            return false;
        vector<bool> check(s2.size()+1, false);        
        for(int i=0; i<s1.size()+1; i++)
        {
            for(int j = 0; j<s2.size()+1; j++)
            {
                if(i==0 && j==0)
                    check[j] = true;
                else if(i==0)
                    check[j] = (check[j-1] && s2[j-1] == s3[j-1]);
                else if(j==0)
                {
                    check[j] = (check[j] && s1[i-1] == s3[i-1]);
                }
                else
                    check[j] = ((check[j] && s1[i-1] == s3[i+j-1]) || (check[j-1] && s2[j-1] == s3[i+j-1]) );
            }   
        }
        
        return check[s2.size()];
    }
};
