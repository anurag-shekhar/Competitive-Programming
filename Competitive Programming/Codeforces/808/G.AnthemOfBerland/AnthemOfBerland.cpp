#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(string &t, string &s) {

    ll count = 0;
    string combine = s+"#"+t;
    int k = s.size();
    int n = combine.size();
    vector<int> pi(n);
    map<char, vector<int> > m;

    for(int i = 0; i<k; i++)
      m[s[i]].push_back(i);

    pi[0] = 0;
    int maxPrefix = 0;

    for(char a : combine)
      cout<<a<<" ";
    cout<<endl; 
    cout<<pi[0]<<" "; 
    for(int i = 1; i<n; i++)
    {
      int j = pi[i-1];
      while(j>0 && combine[i]!='?' && combine[i] != combine[j] )
        j = pi[j-1];
      if(combine[j] == '#')
      {
          
      }
      else if(combine[i]==combine[j] || combine[i]=='?')
        j++;
      pi[i] = j;
      cout<<pi[i]<<" ";
      if(i>k && pi[i]==k)
        count++;
      if(i==k-1)
        maxPrefix = pi[i];  
    }
    cout<<endl;
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
   {
      string t,s;
      cin>>t>>s;
      cout<<solve(t,s)<<endl;
    }

    return 0;
}
