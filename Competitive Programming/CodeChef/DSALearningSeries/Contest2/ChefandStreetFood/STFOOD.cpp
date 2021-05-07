#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(ll n,  vector<vector<ll> > &A) {
    ll count = 0;

    for(int i = 0; i<n; i++)
    {
      A[i][0]+=1;
      count = max(count, A[i][2] * (A[i][1]/A[i][0]));
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      vector<vector<ll> > A(n,vector<ll>(3));
      for(int i = 0;i<n;i++)
        cin>>A[i][0]>>A[i][1]>>A[i][2];
      cout<<solve(n,A)<<endl;
    }

    return 0;
}
