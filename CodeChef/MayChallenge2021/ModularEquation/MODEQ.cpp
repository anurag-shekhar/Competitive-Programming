#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(ll n, ll m) {
    
    int x = (5%3)%2;
    int y = (5%2)%3;

    cout<<x<<" "<<y<<endl;
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,m;
      cin>>n>>m;
      cout<<solve(n,m)<<endl;
    }

    return 0;
}