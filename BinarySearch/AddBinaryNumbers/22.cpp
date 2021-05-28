/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 22.cpp
 * Created on : Fri May 28 2021
 ****************************************************************
 */

string solve(string a, string b) {
    
    if(a.size() < b.size())
        return solve(b,a);

    int na = a.size();
    int nb = b.size();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry=0;
    int i;
    for(i = 0; i<na; i++)
    {
        int sum = (a[i]-'0') + carry;
        if(i<nb)
            sum += (b[i]- '0');
        a[i] = ((sum%2) + '0');
        carry = sum/2;
    }
    if(carry)
        a+=to_string(carry);

    reverse(a.begin(), a.end());
    return a;

}
