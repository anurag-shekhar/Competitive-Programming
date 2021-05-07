#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string solve(ll r, ll b, ll d) {


    if(min(r,b)*d >= abs(r-b))
      return "YES";
    return "NO";


}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll r,b,d;
      cin>>r>>b>>d;
      cout<<solve(r,b,d)<<endl;
    }

    return 0;
}
