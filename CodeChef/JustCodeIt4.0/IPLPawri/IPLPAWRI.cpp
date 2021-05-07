#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define ld long double
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ld solve(ld n,  vector<ld> &A) {
    unordered_map<ld,ld> m;
    m.clear();
    for(int a : A)
    {
        if(m.find(a)==m.end())
            m[a] = 1;
        else 
            m[a]++;    
    }

    ld res = 0;
    for(pair<ld,ld> p : m)
    {
        if(p.second == 3)
        {
            res = p.second * p.first;
        }
    }        
    return res;    
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ld n;
      cin>>n;
      vector<ld> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cout<<solve(n,A)<<endl;
    }

    return 0;
}