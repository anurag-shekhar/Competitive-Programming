#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

bool isPerfectSqaure(ll a)
{
  ll left = 1, right = a;

  while(left <=right)
  {
    ll mid = (right-left)/2 + left;
    if(mid * mid == a)
      return true;
    else if(mid * mid < a)
      left = mid + 1;
    else 
      right = mid - 1;    
  }
  return false;
}
string solve(ll n,  vector<ll> &A) {
    for(int i = 0; i<n; i++)
    {
      if(!isPerfectSqaure(A[i]))
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
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cout<<solve(n,A)<<endl;
    }

    return 0;
}
