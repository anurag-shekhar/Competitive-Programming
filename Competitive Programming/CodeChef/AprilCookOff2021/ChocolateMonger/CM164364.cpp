#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(ll n,ll x , vector<ll> &A) {
    ll count = 0;
    unordered_set<int> s;

    for(int i = 0; i<n; i++)
    {
      auto itr = s.find(A[i]);
      if(itr == s.end())
        s.insert(A[i]);
      else 
        count++;  
    }    
    

    if(count >= x)
      return s.size();
    x -= count;
    x= s.size()-x;
    return max(x, (ll)0); 
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,x;
      cin>>n>>x;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cout<<solve(n,x,A)<<endl;
    }

    return 0;
}
