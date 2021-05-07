#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(ll n,  vector<vector<int> > &A) {
    
    for(int i = 0; i<n; i++)
    {
        ll res = A[i][1]/2;
        if(A[i][1]%2)
          res += abs(A[i][0] - A[i][2]);
        cout<<res<<endl;  
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll g;
      cin>>g;
      vector<vector<int> > A(g,vector<int>(3));
      for(int i = 0;i<g;i++)
        cin>>A[i][0]>>A[i][1]>>A[i][2];
      solve(g,A);
    }

    return 0;
}
