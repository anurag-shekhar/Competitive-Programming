#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll solve(string &s) {

    ll n = s.size();

    ll res = 0;
    ll i =1;
    while(i<n)
    {
      i++;
      res += 9;
    }

    ll num = stol(s);
    ll form = 0;
    while(i--)
      form = form*10 + 1;
    i = form;  
    while(form <= num)
    {
      form += i;
      res++;
    }   
    return res;

}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      string n;
      cin>>n;
      cout<<solve(n)<<endl;
    }

    return 0;
}
