#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve(ll n,ll &count) {
  if(n==2)
    return;
  if(n<2)
  {
    count = -1;
    return;
  }  
  if(n>5 && n%5==0)
  {
    count++;
    solve(n/5, count);
    return ;
  }
  count++;
  solve(n-3,count);
  return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      ll count = 0;
      solve(n,count);
      cout<<count<<endl;
    }

    return 0;
}
