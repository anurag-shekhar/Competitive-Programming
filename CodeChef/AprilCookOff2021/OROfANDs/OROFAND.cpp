#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


void build(vector<ll> &segTree, vector<ll> &A,ll v, ll tl,ll tr)
    {
        if(tl==tr)
            segTree[v] = A[tl];
        else 
        {
            ll tm  = (tr - tl)/2 + tl;
            build(segTree, A, 2*v, tl, tm );
            build(segTree, A,2*v+1, tm+1 ,tr ); 
            segTree[v] = (segTree[2*v] | segTree[2*v +1]);  
        }     
    }

ll ORQuery(vector<ll> &segTree, ll v, ll tl, ll tr, ll l, ll r)
{
    //cout<<"query :"<<v<<endl;
    if(r < l)
        return 0;
    if(tl==l && tr == r)
        return segTree[v];
  
    {
        ll tm  = (tr - tl)/2 + tl;
        ll leftChild = ORQuery(segTree, 2*v, tl, tm, l, min(tm,r));
        ll rightChild = ORQuery(segTree, 2*v+1, tm+1, tr, max(tm+1, l), r);
        return (leftChild | rightChild);
    }
}

void updateTree(vector<ll> &segTree, ll v, ll tl, ll tr, ll pos, ll val)
{
    //cout<<"update :"<<v<<endl;
    if(tl == tr && pos == tl)
        segTree[v] = val;
    else 
    {
        ll tm = (tr - tl)/2 + tl;
        if(tm >= pos)
            updateTree(segTree, 2*v, tl, tm, pos, val);
        else 
            updateTree(segTree, 2*v+1, tm+1, tr, pos, val);

        segTree[v] = (segTree[2*v] | segTree[2*v+1]);        
    }    
}


ll solve(ll n,ll q, vector<ll> &A, vector<vector<ll> > &Q) {
    ll count = 0;

    vector<ll> segTree(4*n+1);
    build(segTree, A,1,0,n-1);
    cout<<ORQuery(segTree, 1,0, n-1, 0, n-1)<<endl;

    for(int i = 0; i<q; i++)
    {
      updateTree(segTree, 1,0,n-1,Q[i][0]-1,Q[i][1]);
      cout<<ORQuery(segTree, 1,0, n-1, 0, n-1)<<endl;
    }
    return count;
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,q;
      cin>>n>>q;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      vector<vector<ll> > Q(q);
      for(int i = 0;i<q;i++)
      {
        ll x,v;
        cin>>x>>v;
        Q[i].push_back(x);
        Q[i].push_back(v); 
      }
      solve(n,q,A,Q);
    }

    return 0;
}
