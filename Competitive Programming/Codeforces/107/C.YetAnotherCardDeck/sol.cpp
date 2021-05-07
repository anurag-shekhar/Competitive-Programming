#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
void solve(ll n, int q, vector<ll> &A, vector<ll> &Q) {
    list<int> idx;
    for(int i = 0; i<n; i++)
    {
        idx.push_back(A[i]);
    }
    for(int i = 0; i<q; i++)
    {
        auto itr = idx.begin();
        int index = 0; 
        for(itr = idx.begin(); itr!=idx.end(); itr++)
        {
          if(*itr == Q[i])
            break;
          index++;  
        }
        cout<<index+1<<" ";
        idx.erase(itr);
        idx.push_front(Q[i]);
    }
}

int main() {
    
    DND;
	
    int t = 1;
    while(t--) {
      ll n,q;
      cin>>n>>q;
      vector<ll> A(n), Q(q);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      for(int i = 0;i<q;i++)
        cin>>Q[i];
      solve(n,q,A,Q);   
      cout<<endl;
    }

    return 0;
}
