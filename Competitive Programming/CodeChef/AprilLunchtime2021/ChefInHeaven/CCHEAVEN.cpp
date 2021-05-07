#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string solve(ll n,  string &s) {
   
  int ones = 0, zeroes = 0;
   
   for(int i = 0; i<n; i++)
   {
      if(s[i]=='1')
        ones++;
      else 
        zeroes++;

      if(2*ones >= (i+1))
        return "YES";  
   }
   return "NO";
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      string s;
      cin>>s;
      cout<<solve(n,s)<<endl;
    }

    return 0;
}
