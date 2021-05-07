#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(ll n,  string &s) {
    
    vector<ll> prefix(n), suffix(n);
    ll count_p = 0, count_s = 0;

    for(int i = 0; i<n; i++)
    {
      if(i!=0)
      {  
        prefix[i] = prefix[i-1];
        suffix[n-i-1] = suffix[n-i];
      }
      else 
      {
          prefix[i] = 0;
          suffix[n-i-1] = 0;
      }

      if(s[i] == '*')
         count_p++;
      else 
        prefix[i] += count_p;  

      if(s[n-i-1] == '*')
        count_s++;
      else 
        suffix[n-i-1] += count_s;  
    }
    
    ll res = LLONG_MAX;

    for(int i = 0; i<=n; i++)
    {
      if(i==0)
        res = min(res,suffix[i]);
      else if(i==n)
        res = min(res, prefix[i-1]);
      else 
        res = min(res , prefix[i-1] + suffix[i]);    
    }
    return res;
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      string A;
      cin>>A;
      cout<<solve(n,A)<<endl;
    }

    return 0;
}