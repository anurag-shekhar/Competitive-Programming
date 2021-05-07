#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

string solve(ll n,  vector<ll> &A) {
  set<ll> s;
  map<ll,ll> m;
  for(int a : A)
    m[a]++;

  for(pair<ll,ll> a : m)
    s.insert(a.second);

  if(s.size() == m.size())
    return "Yes";
  return "No";      
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cout<<solve(n,A)<<endl;
    }

    return 0;
}
