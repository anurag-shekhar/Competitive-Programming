#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll solve(ll r, ll c,  vector<vector<ll> > &A, int k) {
    ll count = 0;

    for(int i = 0; i<r; i++)
    {
        for(int j = 0; j<c ; j++)
        {
            if(i==0 && j==0)
                continue;
            if(i==0)    
                A[i][j] += A[i][j-1];
            else if(j==0)
                A[i][j] += A[i-1][j];
            else 
                A[i][j] += (A[i][j-1] + A[i-1][j] - A[i-1][j-1]);
        }
    }


    for(int l = 1; l<=min(r,c); l++)
    {
        for(int i = l-1; i<r; i++)
        {
            for(int j = l-1; j<c; j++)
            {

                int upperBox = 0,leftBox = 0, diagonalBox = 0;
                if(i-l >=0)
                    upperBox = A[i-l][j];
                if(j-l >=0)
                    leftBox = A[i][j-l];
                if(upperBox && leftBox)
                    diagonalBox = A[i-l][j-l];

                ll numerator = (A[i][j] - upperBox - leftBox + diagonalBox);
                ll check = numerator / (l*l);
                if(check >= k)
                    count++;
            }
        }
    }

    // for(vector<ll> v : A)
    // {
    //     for(ll a : v)
    //         cout<<a<<" ";
    //     cout<<endl;    
    // }
    return count;
}

int main() {
    
    DND
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,m,k;
      cin>>n>>m>>k;
      vector<vector<ll> > A(n,vector<ll>(m));
      for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>A[i][j];
      cout<<solve(n,m,A,k)<<endl;
    }

    return 0;
}