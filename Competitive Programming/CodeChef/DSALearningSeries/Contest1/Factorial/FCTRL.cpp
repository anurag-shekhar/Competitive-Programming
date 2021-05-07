#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(ll n, vector<ll> &A) {
    
    for(int i = 0; i<n; i++)
    {
      ll count = 0;
      ll five = 5;
      while(A[i]/five)
      {
          count += A[i]/five;
          five *= 5;
      }
      A[i]=count;
    }  
    for(ll a : A)
      cout<<a<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
   {
      ll n;
      cin>>n;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
      {  
        cin>>A[i];
        
      }  
      solve(n,A);
    }

    return 0;
}
