#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(ll n,  vector<ll> &A) {
    ll count = 0;

    stack<ll> s;

    for(ll a : A)
    {
      while(!s.empty() && s.top()>=a)
        s.pop();
      if(s.empty())
        count++;
      s.push(a);  
    }
    return count;
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
