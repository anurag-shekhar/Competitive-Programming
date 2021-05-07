#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long int ll;

ll solve(ll n) {

  unordered_map<int,int> m;
  m[0] = 0;
  m[1] = 16;
  m[2] = 28;
  m[3] = 39;

  ll res = 0;
  ll divBy4 = n/4;
  ll extraDice = n%4;
  if(divBy4>=1)
  {
    res += 44*divBy4;
    res+=16;
  } 
  else 
    res+= extraDice*4;

  res += m[extraDice];
  return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      cout<<solve(n)<<endl;
    }
    return 0;
}
