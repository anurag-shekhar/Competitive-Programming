#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(ll n,  vector<ll> &A) {
    ll count = 0;
    ll count1 = 0, count2 = 0, count3 = 0;

    for(ll a : A)
    {
      if(a==1)
        count1++;
      else if(a==2)
        count2++;
      else 
        count3++;    
    }
    return count1 + count3;

}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cout<<solve(n,A)<<endl;
    }

    return 0;
}
