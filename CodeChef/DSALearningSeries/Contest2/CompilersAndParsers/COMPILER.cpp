#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(string &s) {
    stack <char> stk;
    ll i;
    for(i = 0; i<s.size(); i++)
    {
        if(s[i] == '>')
        {
          if(!stk.empty() && stk.top() == '<')
            stk.pop();
          else 
            return i;  
        }
        else 
          stk.push(s[i]);   
    }
    return i;
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
