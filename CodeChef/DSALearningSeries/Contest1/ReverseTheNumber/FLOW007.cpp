#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(ll n) {
    ll count = 0 ;

    ll factor = 10;
    while(n)
    {
        count = (n%10) + count*factor;
        n/=10; 
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
      cout<<solve(n)<<endl;
    }

    return 0;
}