
#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long int ll;

ll solve(ll x, ll y, string &s) {

    unordered_map<string,ll> m;
    m["CJ"] = x;
    m["JC"] = y;
    m["CC"] = 0;
    m["JJ"] = 0;

    ll sum = 0;
    int n = s.size();
    if(n==1)
      return 0;
    int left = 0, right = 1;
    while(right<n)
    {
      if(s[right] != '?' || right==n-1)
      {
        int len = right - left;
        if(s[left]=='?')
        { int needed;
          int leftover = len - (len/2)*2;
          int val = m["CJ"] * (len/2) + m["JC"]*(len/2);
          if(s[right]=='J')
            needed  = m["CJ"];
          else 
            needed = m["JC"];
          leftover = needed*leftover;    

          sum += min(val,min(val + leftover, min(0, min(leftover,needed))));  
        }
        else if(s[right] == '?')
        {
          int needed;
          int leftover = len - (len/2)*2;
          int val = m["CJ"] * (len/2) + m["JC"]*(len/2);
          if(s[left]=='J')
            needed  = m["JC"];
          else 
            needed = m["CJ"]; 

          leftover = needed*leftover;  

          sum += min(val,min(val + leftover, min(0, min(leftover,needed))));
        }
        else 
        {
          string needed = s.substr(left,1) + s.substr(right, 1);
          int leftover = m[needed];
          int val = m["CJ"] * (len/2) + m["JC"]*(len/2);

          sum += min(val + leftover, leftover);
        }
        left = right;
      }
      right++;   
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    int T =t;
    while(t--) {
      ll x,y;
      cin>>x>>y;
      string s;
      cin>>s;
      cout<<"Case #"<<T-t<<": "<<solve(x,y,s)<<endl;
    }

    return 0;
}
