#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MAX_INT 10000000001

ll solve(vector<ll> &A,vector<ll> &B, ll aSize,ll bSize) {
    ll count = 0;
    vector<ll> s ;
    if(bSize == 1)
    { 
      return aSize;
    }  

    for(ll i = 0; i<bSize-1; i++)
      s.push_back(B[i+1] - B[i]);
    s.push_back(MAX_INT);
    for(ll i = 0; i<aSize-1; i++)
      s.push_back(A[i+1] - A[i]);

    ll n = s.size();
    vector<ll> pi(n);
    pi[0] = 0;
    
    for(ll i = 1; i<n; i++)
    {
      ll j = pi[i-1];
      while(j>0 && s[i] != s[j])
        j = pi[j-1];
      if(s[i] == s[j])
        j++;
      pi[i] = j;

      if(pi[i] == (bSize - 1))
        count++;  
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
   {
      ll tSize,sSize;
      cin>>tSize>>sSize;
      vector<ll> T(tSize), S(sSize);
      for(int i = 0;i<tSize;i++)
        cin>>T[i];
      for(int i = 0;i<sSize;i++)
        cin>>S[i];
        
      cout<<solve(T,S,tSize,sSize)<<endl;
    }

    return 0;
}
