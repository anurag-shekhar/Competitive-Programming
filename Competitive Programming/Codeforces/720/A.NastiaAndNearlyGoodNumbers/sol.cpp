#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
bool check(ll x, int a, int b)
{
    if((x%a==0) && (x%(a*b)!=0))
      return true;
    return false;  

}
bool solveForNo(ll a, ll b)
{
  if(a<b)
    return solveForNo(b,a);
  if(a%b==0)
    return true;
  return false;    
}

vector<ll> solve(ll a, ll b) {

    if(solveForNo(a,b))
      return vector<ll>();

    ll i = a*b;
    vector<ll> res(3);
    while(i<=LLONG_MAX)
    {
      for(ll j = a; j<i; j+=a)
      {
        if(j%(a*b)==0)
          continue;
        if(check(i-j, a,b))
        {
          
            res[0] = j;
            res[1] = i-j;
            res[2] = i;
            unordered_set<ll> s;
            for(ll x : res)
              s.insert(x);
            if(s.size()==3 && s.count(a)==0 &&s.count(b)==0)  
              return res;
        }
          
        if(check(i+j,a,b))
        {
            res[0] = j;
            res[1] = i;
            res[2] = i+j;
            unordered_set<ll> s;
            for(ll x : res)
              s.insert(x);
            if(s.size()==3 && s.count(a)==0 &&s.count(b)==0)  
            return res;
        }
      }
      i+= (a*b);
    }
    return vector<ll>();
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll a,b;
      cin>>a>>b;
      vector<ll> A = solve(a,b);
      if(A.size()==0)
        cout<<"NO";
      else 
        cout<<"YES"<<endl;  
      for(ll a : A)
        cout<<a<<" ";
      cout<<endl;  
      
    }

    return 0;
}
