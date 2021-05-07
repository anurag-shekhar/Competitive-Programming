#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string solve(ll n, ll m, ll k) {

    k -= (m-1)*n;
    k -= (n-1)*m;
    k += (m-1)*(n-1);

  if(k==0)
    return "YES";
  return "NO";
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,m,k;
      cin>>n>>m>>k;
      cout<<solve(n,m,k)<<endl;
    }

    return 0;
}