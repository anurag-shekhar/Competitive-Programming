#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define ld long double
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)



ld solve(ll n, ll k, vector<ll> &arr) {
   
    set<ll> S;
    for(ll a : A)
      S.insert(a);

    priority_queue<ll> maxHeap;
    ll prev = -1;
    ll first = -1;
    ll last = -1;
    vector<ll> myBet(2,0);
    for(ll s : S)
    {
      last = s;
      if(first == -1)
        first = s;

      if(prev!=-1)
        maxHeap.push(s-prev-1);
      prev = s;
    }  
    myBet[0] = max(first - 1, k-last);
    myBet[1] = min(first - 1, k-last);
    while(!maxHeap.empty())
    {
      ll diff = maxHeap.top();
      maxHeap.pop();
      ll numWin = (diff+1)/2;

      if(numWin > myBet[0])    //check bet
      {
        myBet[1] = myBet[0];
        myBet[0] = numWin;
      }
      else if(numWin > myBet[1])
        myBet[1] = numWin;   
    }
    return ((ld)(myBet[0] + myBet[1]))/(ld)k;
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    int T = t;
    while(t--) {
      ll n,k;
      cin>>n>>k;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i]; 
      cout<<fixed;  
      cout<<"Case #"<<T-t<<": "<<setprecision(10)<<solve(n,k,A)<<endl;
    }

    return 0;
}

/*

1  3   7
     6   8
10 9 8 6 5 


1 3 4  7
      6  8 

10 9 8 6 


1 2 3 4 5 6 7 8 9 10
^       ^       ^ 
*/
