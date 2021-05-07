#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int

#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(ll n, ll k, vector<ll> &A) {
    ll count = 0;
    unordered_map<ll,ll> m;

    for(int a : A)
    {
      m[a%k]++;
    }
    ll res = 0;

    for(pair<ll,ll> p : m)
    {
      if(p.first!=0)
        res += p.second%2;
    }
    return 1 + res;
}

int main() {
    
    DND;
	
    int t = 1;
    while(t--) {
      ll n,k;
      cin>>n>>k;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cout<<solve(n,k,A)<<endl;
    }

    return 0;
}
