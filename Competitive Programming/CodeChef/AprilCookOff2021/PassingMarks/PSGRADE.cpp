#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string solve(ll Amin,ll Bmin,ll Cmin,ll Tmin,ll A,ll B, ll C) {

    ll T = A+B+C;
    if(A>=Amin && B >= Bmin && C>= Cmin && T >= Tmin )
      return "YES";
    return "NO";  
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll Amin, Bmin, Cmin, Tmin, A,B,C;
      cin>>Amin >> Bmin >> Cmin >> Tmin >>  A >>B >> C;
      
      cout<<solve(Amin, Bmin, Cmin, Tmin, A,B,C)<<endl;
    }

    return 0;
}
