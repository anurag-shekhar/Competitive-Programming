/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ValidNumber.cpp
 * Created on : Mon May 17 2021
 ****************************************************************
 */

class Solution {
public:
    bool isDecimal(string s, bool exp)
    {
        int n = s.size();
        if(n==0)
            return false;
        
        int i;
        for(i = 0; i<n; i++)
        {
            if(s[i]=='.')
                break;
        }
        
        string beforeDot = s.substr(0,i);
        string afterDot="";
        if(i!=n)
            afterDot = s.substr(i+1);
        
        if(beforeDot[0] == '+' || beforeDot[0] == '-')
            beforeDot = beforeDot.substr(1);
        
        if(beforeDot.size()==0 && afterDot.size()==0)
            return false;
        
        if(afterDot.size() && !isdigit(afterDot[0]))
            return false;
        
        if(isInteger(beforeDot, false) && isInteger(afterDot, false))
            return true;
        return false;
    }
    bool isInteger(string s, bool exp)
    {
        int n = s.size();
        
        if(exp && n==0)
            return false;
        
        for(int i =0; i<n; i++)
        {
            if(!isdigit(s[i]))
                return false;
        }
        return true;
    }
    bool isNumber(string s) {
        int i =0;
        for(i = 0; i<s.size(); i++)
        {
            if(s[i]=='e' || s[i]=='E')
                break;
        }
        
        string decimal = s.substr(0,i);
        string integer ="";
        bool exp = false;
        
        bool isDeci, isInt; 
        if(i!=s.size())
        {
            exp = true;
            integer = s.substr(i+1);
        } 
        
        isDeci = isDecimal(decimal,exp);
        if(integer[0]=='+' || integer[0]=='-')
            integer = integer.substr(1);
        isInt = isInteger(integer, exp);

        if(isDeci && isInt)
            return true;
        return false;
        
        
    }
};
/*
"abc"
"1a"
"1e"
"e3"
"99e2.5"
"--6"
"-+3"
"95a54e53"
"-"
"-3"
"2"
"0089"
"-0.1"
"+3.14"
"4."
"-.9"
"2e10"
"-90E3"
"3e+7"
"+6e-1"
"53.5e93"
"-123.456e789"
*/
