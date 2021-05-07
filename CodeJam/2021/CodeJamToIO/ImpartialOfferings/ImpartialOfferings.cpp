#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(ll n,  vector<ll> &A) {
    ll count = 0;
    ll sum = 0;
    ll prev = 0;
    sort(A.begin(), A.end());
    for(int a : A)
    {
        if(a > prev)
        {
           count++;
           prev = a;
        }  
        sum+=count;
    }
    return sum;
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    int T = t;
    while(t--) {
      ll n;
      cin>>n;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cout<<"Case #"<<T-t<<": "<<solve(n,A)<<endl;
    }

    return 0;
}
