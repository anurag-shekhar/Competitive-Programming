/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MultiplyStrings.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    
    string add(string num1, string num2)
    {
        int n1 = num1.size();
        int n2 = num2.size();
        if(n1 < n2)
            return add(num2, num1);
        
        int carry=0;
        int i1 = n1-1, i2=n2-1; 
        int a,b;
        while(i1>=0)
        {
            a = num1[i1]-'0';
            b = (i2>=0) ? num2[i2]-'0' : 0;
            
            a += (b+carry);
            
            b = a%10;
            num1[i1] = '0' + b;
            carry = a/10;
            i1--;
            i2--;
        }
        if(carry)
            num1 = to_string(carry) + num1;
        return num1;
    }
    
    string multiplication(string num1, int b)
    {
        int carry = 0;
        int n1=num1.size();
        for(int i = 0; i<n1; i++)
        {
            int a = num1[n1-1-i]-'0';
            
            a *= b;
            a += carry;
            int val = a%10;
            num1[n1-1-i] = '0'+val ;
            carry = a/10;
        }
        if(carry>0)
            num1 = to_string(carry) + num1;
        return num1;
    }
    
    string multiply(string num1, string num2) {
        
        string res = "";
        int n2 =num2.size(); 
        
        for(int i = 0; i<n2; i++)
        {
            string product = multiplication(num1, num2[n2-1-i]-'0'); 
            for(int j = 0; j<i; j++)
                product += "0";
            
            
            res = add(res,product);
        }
        int i = 0;
        while(i<res.size() && res[i]=='0')
            i++;
        if(i==res.size())
            return "0";
        
        return res.substr(i);
        
        
    }
};
