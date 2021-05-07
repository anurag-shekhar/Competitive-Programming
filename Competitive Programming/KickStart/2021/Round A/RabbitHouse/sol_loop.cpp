#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll solve(int r,int c,vector<vector<int> > &A,ll count) {

    for(int i = 0;i<r; i++)
    {
      for(int j = 1; j<c; j++)
        A[i][j] = max(A[i][j], A[i][j-1]-1);
      for(int j = c-2; j>=0; j--)
        A[i][j] = max(A[i][j], A[i][j+1]-1);  
    }

    for(int j = 0;j<c; j++)
    {
      for(int i = 1; i<r; i++)
        A[i][j] = max(A[i][j], A[i-1][j]-1);
      for(int i = r-2; i>=0; i--)
        A[i][j] = max(A[i][j], A[i+1][j]-1);  
    }

    for(int i = 0;i<r; i++)
    {
      for(int j = 0; j<c; j++)
        count += A[i][j];
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
      ll count = 0;
      vector<vector<int> > A(r,vector<int>(c));
       
      for(int i =0; i<r;i++)
      {
        for(int j = 0;j<c; j++)
        {
          cin>>A[i][j];
          count -= A[i][j];
        }
      }
      cout<<"Case #"<<T-t<<": "<<solve(r,c,A,count)<<endl;
    }

    return 0;
}




