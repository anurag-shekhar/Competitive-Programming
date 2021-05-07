#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long int ll;

string solve(string &E, string &P) {
   
  unordered_map<char,int> e;
  unordered_map<char,int> p;

  for(char a : E)
    e[a]++;
  for(char a : P)
    p[a]++;

  for(pair<char,int> i : e)
    if(p[i.first] < e[i.first])
      return "NO";
  return "YES";        
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      string E,P;
      cin>>E>>P;
      cout<<solve(E,P)<<endl;
    }

    return 0;
}
