#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string solve(ll n,  vector<ll> &L) {
    ll count = 0;
    string res = "A";

    for(int i = 0; i<n; i++)
    {
      string blockString= "";
      char ch = res.back();
      int iteration = L[i];
      if((i+1)%2) //odd
      {
        while(iteration--)
        {
          ++ch;
          if(iteration==0 && i+1 < n)
          {
            char check = (char)(L[i+1]-1 + 'A');
            check++;
            if(ch < check)
              ch = check;
          }
          blockString += (ch);
        } 
      }
      else //even
      {
          ch = 'A';
          while(iteration--)
            blockString += ch++;
        reverse(blockString.begin(), blockString.end());

      }

      res += blockString;
    }
    return res;
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    int  T = t;
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
