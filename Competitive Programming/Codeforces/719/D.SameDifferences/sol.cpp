#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(ll n,  vector<ll> &A) {

    unordered_map<ll,ll> m;
    ll res=0;

    for(int i = 0; i<n; i++)
    {
      ll diff = A[i]-i;
      auto itr = m.find(diff);
      if(itr == m.end())
        m[diff] = 1;
      else 
      {
        res += m[diff];
        m[diff]++;
      }  
    }  
    return res;
    
}
/*
A[j] - j = A[i] -i
*/
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
