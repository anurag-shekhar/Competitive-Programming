#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(ll n, vector<ll> &cost) {

    ll minOdd=cost[1], minEven=cost[0];
    ll minCost = n*cost[1] + n*cost[0];
    ll sumEven = cost[0], sumOdd = cost[1];
    ll tempOdd, tempEven, visitOdd, visitEven;
    for(int i = 2;i < n; i++){

      if(i%2){
        sumOdd += cost[i];
        visitOdd = i/2+1;
        visitEven = i/2+1;
        minOdd = min(minOdd,cost[i]);
      }
      else {
        visitOdd = i/2;
        visitEven = i/2+1;
        sumEven += cost[i];
        minEven = min(minEven,cost[i]); 
      }
      tempEven = minEven*(n-visitEven) + sumEven;
      tempOdd = minOdd*(n-visitOdd) + sumOdd;
      minCost = min(minCost, tempEven+tempOdd );
    }
    return minCost;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      vector<ll> cost(n);
      for(int i = 0;i<n;i++)
        cin>>cost[i];
      cout<<solve(n,cost)<<endl;
    }

    return 0;
}
