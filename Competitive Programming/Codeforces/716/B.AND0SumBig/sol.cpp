#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define MOD 1000000007

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(ll n,ll k) {
    ll res = 1;

    for(int i = 1; i<=k; i++)
    {
       res = ((res*n)%MOD);
    }
    
    return res%MOD;
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,k;
      cin>>n>>k;
      cout<<solve(n,k)<<endl;
    }

    return 0;
}
