#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string solve(ll n, ll w, ll wr, vector<ll> &A) {
    priority_queue<int> maxHeap;

    w -= wr;
    if(w<=0)
      return "YES";
    for(ll a : A)
      maxHeap.push(a);

    int plate;
    if(!maxHeap.empty())
    {
      plate = maxHeap.top();
      maxHeap.pop();
    }
      

    while(!maxHeap.empty())
    {
      if(plate == maxHeap.top())
      {
        maxHeap.pop();
        w-= 2*plate;
        if(w<=0)
          return "YES";
        if(!maxHeap.empty())
        {
          plate = maxHeap.top();
          maxHeap.pop();
        }
      }
      else 
      {
        plate = maxHeap.top();
        maxHeap.pop();
      }
    }
    return "NO";  
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n,w,wr;
      cin>>n>>w>>wr;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cout<<solve(n,w,wr,A)<<endl;
    }

    return 0;
}
