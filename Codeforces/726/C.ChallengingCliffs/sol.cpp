#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(ll n,  vector<ll> &A) {
    
    sort(A.begin(), A.end());

    vector<int> store;
    for(int i = 0; i<n-1; i++)
    {
        if(A[i] == A[i+1])
        {
            store.push_back(i);
            store.push_back(i+1);
            break;
        }
    }
    if(store.size()==0)
    {
        store.push_back(0);
        store.push_back(1);
    }

    cout<<A[store[0]]<<" ";

    for(int i = store[1]+1; i<n; i++)
        cout<<A[i]<<" ";
    for(int i = 0; i<store[0]; i++)
        cout<<A[i]<<" ";
    cout<<A[store[1]]<<endl;

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
      solve(n,A);
    }

    return 0;
}