#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long int ll;

string solve(ll n, ll k, string &s) {
    
    int left = -1, right = 0;
    int maxLen = 0;
    
    while(right < n)
    {
      if(s[right]=='*')
      {
        if(k<=(right-left))
          return "YES";
      }  
      else
        left = right; 
      right++;  
    }

    return "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,k;
      cin>>n>>k;
      string s;
        cin>>s;
      cout<<solve(n,k,s)<<endl;
    }

    return 0;
}
