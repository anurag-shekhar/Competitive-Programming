#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(ll n,   vector<vector<ll> > &A) {
    ll count = 0;

    for(int i = 0; i<n; i++)
    {
      for(int j = 0; j<n; j++)
      {
        for(int p = i; p<n; p++)
        {
          for(int q = j; q<n; q++)
          {
            if(A[i][j] > A[p][q])
              count++;
          }
        }
      }
    }
    return count;
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      vector<vector<ll> > A(n,vector<ll>(n));
      for(int i = 0;i<n;i++)
        for(int j = 0; j<n; j++)
          cin>>A[i][j];
      cout<<solve(n,A)<<endl;
    }

    return 0;
}
