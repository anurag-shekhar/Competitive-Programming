#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long int ll;

string solve(int n, string &S, int x, int y, int z) {

  vector<pair<char, int> > sFreq;
  for(int i =0 ; i<S.size(); i++)
  {
    int count  = 1;
    i++;
    while(i<S.size() && )
  }      
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      int n,x,y,z;
      string S;

      cin>>n>>S>>x>>y>>z;
      cout<<solve(n,S,x,y,z)<<endl;
    }

    return 0;
}

