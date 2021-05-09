/*
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CountNicePairsInAnArray.cpp
 * Created on : Sun May 09 2021
 */


#define MOD 1000000007
#define ll long long int
class Solution {
public:
    
    
    ll reverseMinus(ll A)
    {
        ll a = A;
        ll b = 0;
        while(a)
        {
            b = b*10 + (a%10);
            a /= 10;
        }
        
        return (A-b);
        
    }
    int countNicePairs(vector<int>& nums) {
        
        unordered_map<ll, ll> m;
        
        for(int a : nums)
        {
            ll b = reverseMinus(a);
            m[b]++;
        }
        
        int res = 0;
        
        for(pair<ll,ll> i : m)
        {
            res += (((i.second-1)*(i.second)/2)%MOD);
        }
        
        return res % MOD;
        
        
        
    }
};
