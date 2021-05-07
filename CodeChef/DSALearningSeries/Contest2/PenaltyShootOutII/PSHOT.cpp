#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(ll n,  string &s) {
    ll i;
    ll scoreA = 0,scoreB = 0;
    ll chanceA = n, chanceB = n;
    for(i = 0; i<2*n; i++)
    {
      if(i%2)
      {
         scoreB += s[i] - '0';
         chanceB--;
      } 
      else
      {
        scoreA += s[i] - '0';
        chanceA--;
      }
      if(scoreA > scoreB + chanceB)
        return i+1;
      else if(scoreB > scoreA + chanceA)
        return i+1;       

    }
    return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      string s;
      cin>>s;
      cout<<solve(n,s)<<endl;
    }

    return 0;
}
