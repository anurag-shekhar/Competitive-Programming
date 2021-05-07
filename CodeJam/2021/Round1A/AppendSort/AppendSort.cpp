#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll countDigit(ll a)
{
    ll count = 0;
    while(a)
    {
      count++;
      a/=10;
    }
    return count;
}

ll solve(ll n,  vector<ll> &A) {
    ll count = 0;
    for(ll i = 1; i<n; i++)
    {
        ll currDigit=0;
        while(A[i] <= A[i-1])
        {
          ll diffDigit = countDigit(A[i-1] - A[i]+1) ;
          
          if(currDigit < diffDigit)
          {
            A[i] = A[i]*10;
            currDigit++;
          }  
          else 
            A[i] += (A[i-1]-A[i]+1);
        }
        count += currDigit;
    }

    for(int a : A)
      cout<<a<<" ";
    cout<<endl;    
    return count;
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
