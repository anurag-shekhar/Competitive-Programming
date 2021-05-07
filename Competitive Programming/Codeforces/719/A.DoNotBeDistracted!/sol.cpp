#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string solve(ll n,  string &A) {

      unordered_set<char> s;
      for(ll i  = 0; i<n; i++)
      {
        if(s.find(A[i]) != s.end())
          return "NO";
        s.insert(A[i]);  
        while(i+1<n && A[i]==A[i+1])
          i++;
      }
      return "YES";
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      string A;
      cin>>A;
      cout<<solve(n,A)<<endl;
    }

    return 0;
}
