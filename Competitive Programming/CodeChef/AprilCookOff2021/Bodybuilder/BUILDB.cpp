#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(ll n, ll r , vector<ll> &A, vector<ll> &B) {
    ll maxW = B[0];
    ll weight = B[0];
    for(int i = 1; i<n; i++)
    {
         weight = max(weight - r*(A[i]-A[i-1]), (ll)0);
         weight += B[i];

         maxW = max(weight, maxW); 
    }
    return maxW;
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,r;
      cin>>n>>r;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      vector<ll> B(n);
      for(int i = 0;i<n;i++)
        cin>>B[i];  
      cout<<solve(n,r,A,B)<<endl;
    }

    return 0;
}
