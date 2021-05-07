#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(ll n,  vector<ll> &A) {
    ll count = 0;
    sort(A.begin(), A.end());
    
    for(ll i = 0; i<n; i++ )
    {
      count = max(count, A[i]*(n-i));
    }    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    {
      ll n;
      cin>>n;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cout<<solve(n,A)<<endl;
    }

    return 0;
}
