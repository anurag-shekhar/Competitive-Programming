#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007

void solve(ll n,  vector<ll> &A, ll q,  vector<ll> &Q) {
    ll sum = 0;
    for(int i = 0; i<n; i++)
    {
      sum  =  (sum+A[i]);
    }

    for(int i = 0; i<q; i++)
    {
      sum = sum+sum;
      while(sum<0)
        sum+=MOD;
      sum%=MOD;
      cout<<sum%MOD<<endl;
    }
}

int main() {
    
    DND;
	
    int t = 1;
    while(t--) {
      ll n,q;
      cin>>n;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cin>>q;
      vector<ll> Q(q);
      for(int i = 0; i<q; i++)
        cin>>Q[i];
      solve(n,A,q,Q);  
      cout<<endl;
    }

    return 0;
}
