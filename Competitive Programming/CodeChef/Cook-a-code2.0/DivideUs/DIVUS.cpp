#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long int ll;

bool prefixFunction(string s,string t)
{
    string A = s+"#"+t;
    int n = A.size();

    vector<int> pi(n);

    pi[0]=0;
    int count  = 0; 
    for(int i = 1; i<n; i++)
    {
      int j = pi[i-1];
      while(j>0 && A[i]!=A[j])
        j = pi[j-1];
      if(A[i]==A[j])
        j++;
      pi[i] = j;

      if(pi[i] == s.size())
        count++;     
    }
    if(count == 3 )
      return true;
    return false;  

}

string solve(ll n,  string &s) {
    ll count = 0;

    vector<int> prefixOnes(n);

    int countOne = 0;
    for(int i =0; i<n; i++)
    {
      if(s[i]=='1')
        countOne++;
      if(i==0)
        prefixOnes[i] = s[i] =='1' ?1:0;
      prefixOnes[i] = prefixOnes[i-1] + (s[i]-'0');  
    }
    if(countOne==0)
    {
      if(n>=3)
        return "Yes";
      else
        return "No";  
    }
    if(countOne%3)
      return "No";

    int seg1 = countOne/3;
    if(seg1%2==0)
      return "Yes";
    int i;
    for(i = n-1; i>=0 ; i--)
    {
      if(s[i]=='1')
        seg1--;
      if(seg1==0)
        break;

    }
    string t = s.substr(i,n-i);

    if(prefixFunction(t,s))
      return "Yes";
    return "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
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
