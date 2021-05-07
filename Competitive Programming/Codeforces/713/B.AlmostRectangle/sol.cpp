#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(ll n,  vector<vector<char> > &A) {
    vector<pair<int,int> > coordinate;

    for(int i = 0;i < n; i++)
    {
      for(int j = 0; j<n; j++)
      {
        if(A[i][j] == '*')
          coordinate.push_back(make_pair(i,j));
      }
    }
    pair<int,int> a = coordinate[0];
    pair<int,int> b = coordinate[1];
    if(a.second == b.second) //in same column
    {
      if(a.second +1 < n)
      {
          A[a.first][a.second+1] = '*';
          A[b.first][b.second+1] = '*';
      } 
      else 
      {
          A[a.first][a.second-1] = '*';
          A[b.first][b.second-1] = '*';
      }
    }
    else if(a.first == b.first) // in same row
    {
        if(a.first+1 < n)
        {
            A[a.first+1][a.second] = '*';
            A[b.first+1][b.second] = '*';
        } 
        else 
        {
            A[a.first-1][a.second] = '*';
            A[b.first-1][b.second] = '*';
        }
    }
    else 
    {
        A[a.first][b.second] = '*';
        A[b.first][a.second] = '*';
    }


    for(vector<char> V : A)
    {
      for(char c:V)
        cout<<c;
      cout<<endl;  
    }
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      vector<vector<char> > A(n,vector<char>(n));
      for(int i = 0;i<n;i++)
        for(int j = 0; j<n; j++)
          cin>>A[i][j];
      solve(n,A);    
    }

    return 0;
}
