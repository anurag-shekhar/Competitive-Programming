/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RomanToInteger.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */


class Solution {
public:
    int romanToInt(string s,int i = 0) {
        
        if(i==s.size())
            return 0;
        vector<int> I = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> C = {"I","IV","V", "IX", "X", "XL","L", "XC","C", "CD", "D", "CM", "M"};
        unordered_map<char,string> m;
        m['I'] = "VX";
        m['X'] = "LC";
        m['C'] = "DM";
        
        int j;
        string comp = s.substr(i,1);
        //cout<<comp<<endl;
        if(i+1<s.size())
        {
            if(m[s[i]][0] == s[i+1])
                comp+=s[i+1];
            if(m[s[i]][1] == s[i+1])
                comp+=s[i+1];
        }
            
        for(j = C.size()-1; j>=0; j--)
            if(comp==C[j])
                break;
        return I[j] + romanToInt(s,i+comp.size());
        
    }
};
