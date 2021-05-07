#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(ll n,  vector<ll> &A) {
    ll count = 0;

    stack<int> s;

    for(int i = n-1; i>=0; i--)
    {
        while(!s.empty() && A[i] < A[s.top()])
          s.pop();
        s.push(i); 
    }
    while(!s.empty())
    {
      int currIdx = s.top();
      s.pop();
      if(s.empty())
        count += (n-currIdx)*A[currIdx];
      else 
        count += (s.top() - currIdx) * A[currIdx];   
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
