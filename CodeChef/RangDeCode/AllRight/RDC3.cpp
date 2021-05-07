#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(ll n,  vector<ll> &A, int k ,int dist,ll &sum) {

      if(n==dist)
        return;
      int i = n-dist-1;  

      int ops = A[i]/2;

      //cout<<"k : "<<k<<" "<<"dist : "<<dist<<" "<<"sum : "<<sum<<" "<<"i : "<<i<<" "<<"val : "<<val<<" "<<endl;

      if((ops*dist) >= k)
      {
        sum += (k/dist)*2;
        return;
      }
      else
      {
        sum += (A[i]/2)*2;
        k -= (ops*dist);
        solve(n,A,k,dist+1,sum);
      }   

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,k;
      cin>>n>>k;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      ll sum = 0;  
      solve(n,A,k,1,sum);
      sum = A[n-1]+sum;
      cout<<sum<<endl;
    }

    return 0;
}
