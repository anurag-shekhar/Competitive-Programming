/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LongerContiguousSegmentsOfOnesThanZeros.cpp
 * Created on : Sun May 23 2021
 ****************************************************************
 */

class Solution {
public:
    bool checkZeroOnes(string s) {
        
        int longest1 = 0;
        int longest0 = 0;
        
        for(int i = 0; i<s.size();)
        {
            string temp = "";
            if(s[i]=='0')
            {
                while(i<s.size() && s[i]=='0')
                    temp += s[i++];
                int size = temp.size();
                longest0 = max(longest0, size);
            }
            else
            {
                while(i<s.size() && s[i]=='1')
                    temp += s[i++];
                int size = temp.size();
                longest1= max(longest1 ,size);
            }
        }
        //cout<<longest1<<" "<<longest0;
        return longest1 > longest0;
    }
};
