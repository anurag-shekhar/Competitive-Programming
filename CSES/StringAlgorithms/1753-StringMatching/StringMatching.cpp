#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(string &t, string &s) {
    ll count = 0;
    string mano = s + "#" + t;
    ll n = mano.size();
    vector<ll> pi(n);
    pi[0] = 0;
    for(ll i =1; i<n; i++)
    {
        ll j = pi[i-1];
        while(j>0 && mano[i]!=mano[j])
          j = pi[j-1];
          
        if(mano[j] == mano[i])
          j = j + 1;
        pi[i] = j; 
        if(pi[i] == s.size())
          count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
  {
      string t,s;
      cin>>t>>s;
      cout<<solve(t,s)<<endl;
    }

    return 0;
}
