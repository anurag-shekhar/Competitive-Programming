/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 419.cpp
 * Created on : Fri Jun 04 2021
 ****************************************************************
 */


string solve(string a, string b) {
    
    if(a.size() < b.size())
        return solve(b,a);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());    

    int carry = 0;

    for(int i = 0; i<a.size(); i++)
    {
        int sum = (a[i]-'0') + carry;
        
        if(i<b.size())
            sum += (b[i]-'0');

        a[i] = (sum%10 + '0');
        carry = sum/10;    
    }
    while(carry)
    {
        int sum = carry;
        a.push_back((sum%10 + '0'));
        carry /= 10;
    }
    reverse(a.begin(), a.end());
    return a;
}
