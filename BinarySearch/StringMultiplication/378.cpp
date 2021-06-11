/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 378.cpp
 * Created on : Sat Jun 12 2021
 ****************************************************************
 */

string add(string a, string b)
{
    int n_a = a.size();
    int n_b = b.size();
    if(n_a < n_b)
        return add(b,a);

    int carry = 0;
    for(int i = 0; i<n_a; i++)
    {
        int sum = a[i]-'0' + carry;

        if(i<n_b)
            sum += b[i]-'0';
        
        carry  = sum/10;
        sum %= 10;

        a[i] = (sum + '0');
    }

    if(carry)
    {
        a += (carry+'0');
    }
    return a;
}
string multiply(string a, int b)
{
    int n_a = a.size();
    int carry = 0;
    for(int i = 0; i<n_a; i++)
    {
        int sum = (a[i]-'0')*b + carry;

        carry = sum/10;
        sum %=10;
        a[i] = (sum+'0');
    }
    if(carry)
    {
        a += (carry+'0');
    }
    return a;
}
string solve(string a, string b) {

    int n_a = a.size();
    int n_b = b.size();
    if(n_a < n_b)
        return solve(b,a);


    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int neg_flag = 1;

    if(a.back() == '-')
    {
        neg_flag *= -1;
        a.pop_back();
    }
    if(b.back() == '-')
    {
        neg_flag *= -1;
        b.pop_back();
    }

    string res = "0";
    for(int i = 0; i<n_b; i++)
    {
        string val = multiply(a,b[i]-'0');

        int numZeroes = i;
        while(numZeroes--)
        {
            val = "0" + val;
        }
        res = add(res, val);
    }
    while(res.size()>1)
    {
        if(res.back()=='0')
            res.pop_back();
        else 
            break;
    }
    if(neg_flag == -1)
        res += "-";
    reverse(res.begin(), res.end());
    return res;
}

/*

    15.   51
    18    81
     0.   0 2 1
          

*/
