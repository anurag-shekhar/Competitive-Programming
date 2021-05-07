#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll findPrimeFactor(ll &num, int p)
{
    ll count = 0;
    while(num%p == 0)
    {
        count++;
        num /= p;
    }
    return count;
}

ll findExponent(ll low, ll high, ll target)
{
    
}


ll solve(ll k) {
    ll num = k;
    unordered_map<ll,ll> primeFactor;
    ll prime2 = primeFactor(num,2);
    if(!prime2)
        primeFactor[2] = prime2;
    for(ll i = 3; i<=k; i+=2)
    {
        ll prime = primeFactor(num,i);
        if(!prime)
            primeFactor[i] = prime;
    }    
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,k;
      cin>>k;
      cout<<solve(k)<<endl;
    }

    return 0;
}