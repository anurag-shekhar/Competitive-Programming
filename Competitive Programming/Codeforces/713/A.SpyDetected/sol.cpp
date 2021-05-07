#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(ll n,  vector<ll> &A) {
    
    int prevVal = A[0];
    int prevIdx = 0;
    map<ll,ll> m; 
    
    for(ll a : A)
      m[a]++;

    ll val;
    if(m.begin()->second == 1)
      val = m.begin()->first;
    else 
      val = m.rbegin()->first;     

    for(int i = 0; i < n; i++)
    {
        if(val == A[i])
          return i+1;
    }
    return 0;
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cout<<solve(n,A)<<endl;
    }

    return 0;
}
