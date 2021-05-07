#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(ll n, ll k, vector<ll> &A) {
    
    ll start = (n-(k%n))%n;
    
    for(int i = 0; i<n; i++)
    {
      cout<<A[start%n]<<" ";
      start++;
    }  
}


int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,k;
      cin>>n>>k;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      solve(n,k,A);  
      cout<<endl;
    }

    return 0;
}
