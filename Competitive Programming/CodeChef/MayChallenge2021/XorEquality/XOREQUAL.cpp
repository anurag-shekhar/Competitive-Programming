#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007;
ll powerOf2(ll n)
{
    if(n==0)
        return 1;
    ll res = powerOf2(n/2);
    res %= MOD;
    res = res*res;
    res %= MOD;
    if(n%2)
        return (2*res)%MOD;
    return res%MOD;  
}


ll solve(ll n) {
    return powerOf2(n-1);
}


int main() {
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      cout<<solve(n)<<endl;
    }

    return 0;
}