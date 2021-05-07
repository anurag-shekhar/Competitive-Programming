#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(ll n) {
    if(n==2)
    {
      cout<<-1<<endl;
      return ;
    }

    vector<vector<int> > A(n,vector<int>(n,0));

    int fill = 1;
    for(int i = 0; i<n; i++)
    {
      for(int j = 0; j<n; j++)
      {
        cout<<fill<<" ";
        fill+=2;
        if(fill>n*n)
        {
            fill = fill%(n*n) + (n+1)%2;
        }
      }
      cout<<endl;
    }
    return ;

}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      solve(n);
    }

    return 0;
}
