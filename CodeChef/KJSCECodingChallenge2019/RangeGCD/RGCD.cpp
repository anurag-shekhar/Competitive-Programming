#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b)
{
  if(a==0)
    return b;
  return gcd(b%a,a);
}

void build(vector<ll> &t, vector<ll> &A,ll v,ll tl, ll tr)
{
  if(tl == tr)
    t[v] = A[tl];
  else 
  {
    ll tm = (tl+tr)/2;
    build(t,A,v*2,tl,tm);
    build(t,A,v*2+1, tm+1, tr);
    t[v] = gcd(t[v*2], t[v*2+1]);
  }  
}

void update(vector<ll> &t,ll v,ll tl, ll tr, ll l, ll r, ll val)
{
  if(l>r)
    return;
  if(tl==tr)
      t[v] *= val;  
  else 
  {
    ll tm = (tl+tr)/2;
  
    update(t, v*2, tl, tm, l, min(tm,r), val);
    update(t, v*2+1, tm+1, tr, max(tm+1,l), r, val);

    t[v] = gcd(t[v*2], t[v*2+1]);      
  }  
}

ll askGCD(vector<ll> &t,ll v,ll tl, ll tr, ll l, ll r)
{
  if(l>r)
    return 0;
  if(tl==l && tr == r)
    return t[v];
  else 
  {
    ll tm = (tl+tr)/2;
    ll leftChildGCD = askGCD(t,v*2,tl,tm, l, min(tm,r));
    ll rightChildGCD = askGCD(t,v*2+1,tm+1, tr, max(tm+1,l),r);

    return gcd(leftChildGCD, rightChildGCD);
  }    
}

void solve(ll n, vector<ll> &A, vector<vector<ll> > &queries)
{
  vector<ll> t(4*n);
  build(t,A,1,0,n-1);

  vector<ll> result;

  for(ll i = 0; i<queries.size(); i++)
  {
    if(queries[i][0]==1)
      result.push_back(askGCD(t,1,0,n-1,queries[i][1],queries[i][2]));
    else 
      update(t,1,0,n-1,queries[i][1],queries[i][2],queries[i][3]);  
  }

  for(ll i = 0; i<result.size(); i++)
    cout<<result[i]<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    ll t = 1;
    cin >> t;
    while(t--) {

      ll n,q;
      cin >> n >>q;
      vector<ll> A(n);
      for(ll i=0; i<n; i++)
        cin>>A[i];
      vector<vector<ll> > queries;
      for(ll i=0;i<q; i++)
      {
        vector<ll> temp;
        queries.push_back(temp);
        queries[i].push_back(0);
        cin>>queries[i][0];
        if(queries[i][0]==1)
        {
          queries[i].push_back(0);
          queries[i].push_back(0);
          cin>>queries[i][1]>>queries[i][2];
        }
        else 
        {
          queries[i].push_back(0);
          queries[i].push_back(0);
          queries[i].push_back(0);
          cin>>queries[i][1]>>queries[i][2]>>queries[i][3];
        }
      }
      solve(n,A,queries);
    }
   

    return 0;
}

