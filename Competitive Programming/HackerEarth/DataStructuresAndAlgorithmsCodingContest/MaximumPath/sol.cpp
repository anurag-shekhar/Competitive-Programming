#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool solve(ll &maxVal,  vector<ll> &A, unordered_set<int> &isVisited, unordered_map<int,vector<int> > &edges, int u , int v) {
    
    if(isVisited.find(u)!=isVisited.end())
      return false;
    isVisited.insert(u);

    if(u==v)
    {
      maxVal = A[v-1];
      return true;
    }
       
    for(int a : edges[u])
    {
        if(solve(maxVal, A, isVisited, edges, a, v))
          maxVal = max(maxVal, A[u-1]);
    } 
    return false; 
}

int main() {
    
    DND;
	
    int t = 1;
    while(t--) {
      ll n,q;
      cin>>n>>q;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      unordered_map<int,vector<int> > edges;  
      for(int i = 0;i<n-1;i++)
      {
        int a,b;
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
      }
      for(int i = 0; i<q; i++)
      {
        int a,b;
        cin>>a>>b;
        unordered_set<int> isVisited;
        ll maxVal = 0;
        solve(maxVal,A,isVisited, edges, a,b);
        cout<<maxVal<<endl;
      }  
    }

    return 0;
}
