/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CompareVersionNumbers.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */


class Solution {
public:
    int compareVersion(string v1, string v2, int i1 = 0, int i2 =0) {
        
        int num1 = 0, num2 = 0;
        if(i1>=v1.size() && i2>=v2.size())
            return 0;
        
        string s1 = "";
        while(i1<v1.size() && v1[i1]!='.')
        {
            s1+= v1[i1];
            i1++;
        }
        string s2 = "";
        while(i2<v2.size() && v2[i2]!='.')
        {
            s2+= v2[i2];
            i2++;
        }
     
        
        for(int i = 0; i<s1.size(); i++)
            num1 = num1*10 + (s1[i]-'0');
        for(int i = 0; i<s2.size(); i++)
            num2 = num2*10 + (s2[i]-'0');
       
        if(num1 > num2)
            return 1;
        if(num2 > num1)
            return -1;
        
        return compareVersion(v1,v2,i1+1,i2+1);
        
        
        
            
        
    }
};
