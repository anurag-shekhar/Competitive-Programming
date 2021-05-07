#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string solve(ll a, ll b, string &s) {

      int n = s.size();
      int left  = 0;
      int right = n-1;
      for(int i = 0; i<n; i++)  //removing all static 0 and 1 counts
      {
        if(s[i]=='0')
          a--;
        else if(s[i]=='1')
          b--;  
      }

      while(left<right)
      {
        if(s[left]!='?' && s[right]!='?')
        {
            if(s[left]!=s[right])
              return "-1";
        }
        else if(s[left]!='?')
        {
            s[right] = s[left];
            if(s[left]=='0')
              a--;
            else 
              b--;  
        }
        else if(s[right]!='?')
        {
            s[left] = s[right];
            if(s[right]=='0')
              a--;
            else 
              b--;  
        }
        else 
        {
            if(a>=b)
            {
              s[left] = '0';
              s[right] = '0';
              a-=2;
            }
            else 
            {
              s[left] = '1';
              s[right] = '1';
              b-=2;
            }
        }

        if(a<0 || b<0)
          return "-1";
        left++;
        right--;  
      }

      if(left == right)
      {
        if(s[left]=='?')
        {
            if(a)
            {
              s[left] = '0';
              a--;
            }
            else 
            {
              s[left] = '1';
              b--;
            }
        }
      }
      if(a!=0 && b!=0)
        return "-1";
      return s;
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll a,b;
      cin>>a>>b;
      string s;
      cin>>s;
      cout<<solve(a,b,s)<<endl;
    }

    return 0;
}
