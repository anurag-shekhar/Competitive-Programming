#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(ll n,  vector<ll> &A) {
    
    unordered_map<ll,int> m;
    for(int i = 0; i<n+2; i++)
      m[A[i]] = i;
    vector<ll> prefix(n+2),suffix(n+2);

    for(int i = 0; i<n+2; i++)
    {
      if(i==0)
      {   
        prefix[i] = A[i];
        suffix[n+1-i] = A[n+1-i];
      }  
      else 
      {
        prefix[i] = A[i] + prefix[i-1];
        suffix[n+1 - i] = suffix[n+1 - i +1] + A[n+1-i]; 
      }    
    }

    // cout<<"prefix =";
    // for(ll a : prefix)
    //   cout<<a<<" ";
    // cout<<"suffix =";
    // for(ll a : suffix)
    //   cout<<a<<" ";

    pair<int,int> res;
    res.first  = -1;
    for(int i = 0; i<n+2; i++)
    {
      ll sum = 0;
      if(i!=0)
        sum+=prefix[i-1];
      if(i!=n+1) 
        sum+=suffix[i+1];

      if(sum%2)
        continue;
      else 
      {
        sum = sum/2;
        auto itr = m.find(sum);
        if(itr!=m.end() && itr->second!=i)
        {
          res.first = i;
          res.second = itr->second;
        }
      }      
    }
    if(res.first == -1)
    {
      cout<<"-1";
      return;
    }      
    for(int i = 0; i<n+2; i++)
    {
      if(res.first==i || res.second==i)
        continue;
      else   
        cout<<A[i]<<" ";
    }
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      vector<ll> A(n+2);
      for(int i = 0;i<n+2;i++)
        cin>>A[i];
      solve(n,A);  
      cout<<endl;
    }

    return 0;
}
