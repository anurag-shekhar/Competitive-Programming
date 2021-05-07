#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

string solve(string &s) {

    for(int i = 0; i<s.size(); i++)
    {
      if(i+1<s.size() && s[i]=='1' && s[i+1]=='1')
      {
        for(int j = i+2; j<s.size(); j++)
        {
          if(j+1<s.size() && s[j]=='0' && s[j+1]=='0')
            return "NO";
        }
      }
    }
    return "YES";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      string s;
      cin>>s;
      cout<<solve(s)<<endl;
    }

    return 0;
}
