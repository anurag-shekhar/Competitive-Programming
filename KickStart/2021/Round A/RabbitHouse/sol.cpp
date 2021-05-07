#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool isValid(int i,int j, int r,int c,vector<vector<bool> > &visited)
{ 
  if(0<=i && 0<=j && j<c && i<r && !visited[i][j])
    return true;
  return false;  
}

ll dfs(vector<vector<int> > &A,vector<vector<bool> > &visited,int x,int y,int r,int c)
{
    ll count = 0;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    visited[x][y] = true;
    for(int i = 0; i<4;i++)
    {
        int new_x = x+dx[i];
        int new_y = y+dy[i];
        if(isValid(new_x,new_y, r,c,visited))
        {
          if((A[x][y] - A[new_x][new_y]) > 1 )
          {  
            count += (A[x][y] - A[new_x][new_y] -1);
            A[new_x][new_y] = A[x][y] - 1;
            //count += dfs(A,visited,new_x,new_y,r,c);
          }
        }  
    }
    visited[x][y] = false;
    return count;
}

ll solve(int r,int c,vector<vector<int> > &A) {
    ll count = 0; 
    vector<vector<bool> > visited(r,vector<bool>(c,false));

    for(int i = 0; i<r; i++)
    {
      for(int j = 0; j<c; j++)
      {
          count += dfs(A,visited, i,j,r,c);
      }
    }
    return count; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t ,T;
    cin >> t;
    T=t;
    while(t--) {
      int r,c;
      cin>>r>>c;
      vector<vector<int> > A(r,vector<int>(c));
       
      for(int i =0; i<r;i++)
      {
        for(int j = 0;j<c; j++)
        {
          cin>>A[i][j];
        }
      }
      cout<<"Case #"<<T-t<<": "<<solve(r,c,A)<<endl;
    }

    return 0;
}




