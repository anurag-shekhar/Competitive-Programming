#include<bits/stdc++.h>
using namespace std;



int solve(int r,int c,vector<vector<int> > &A) {


  vector<vector<int> > left(r,vector<int>(c));
  vector<vector<int> > right(r,vector<int>(c));
  vector<vector<int> > down(r,vector<int>(c));
  vector<vector<int> > up(r,vector<int>(c));

  //left
  for(int i = 0; i<r; i++)
  {
    for(int j =0; j<c; j++)
    {
      if(j>0 && A[i][j]==1)
      {
          left[i][j] = left[i][j-1] + 1; 
      }
      else 
        left[i][j] = A[i][j]; 
    }
  }

  //right
  for(int i = 0; i<r; i++)
  {
    for(int j =c-1; j>=0; j--)
    {
      if(j<c-1 && A[i][j]==1)
      {
          right[i][j] = right[i][j+1] + 1; 
      }
      else 
        right[i][j] = A[i][j];
 
    }
  }

  //down
  for(int j = 0; j<c; j++)
  {
    for(int i =r-1; i>=0; i--)
    {
      if(i<r-1 && A[i][j]==1)
      {
          down[i][j] = down[i+1][j] + 1; 
      }
      else 
        down[i][j] = A[i][j];
 
    }
  }


  //up
  for(int j = 0; j<c; j++)
  {
    for(int i =0; i<r; i++)
    {
      if(i>0 && A[i][j]==1)
      {
          up[i][j] = up[i-1][j] + 1; 
      }
      else 
        up[i][j] = A[i][j];
    }
  }

  int count = 0;
  //checking and counting for each L shape with respect to each cell.
  for(int i = 0; i<r; i++)
  {
    for(int j = 0; j<c; j++)
    {
        if(down[i][j]>1 && right[i][j]>1)
        {
          int half = down[i][j]/2;
          if(half > 1)
            count += min(half,right[i][j]) -1; 
          half = right[i][j]/2; 
          if(half > 1) 
            count += min(half,down[i][j]) -1;
        }
        if(down[i][j]>1 && left[i][j]>1)
        {
          int half = down[i][j]/2;
          if(half > 1)
            count += min(half,left[i][j]) -1; 
          half = left[i][j]/2; 
          if(half > 1) 
            count += min(half,down[i][j]) -1;
        }
        if(up[i][j]>1 && right[i][j]>1)
        {
          int half = up[i][j]/2;
          if(half > 1)
            count += min(half,right[i][j]) -1; 
          half = right[i][j]/2; 
          if(half > 1) 
            count += min(half,up[i][j]) -1;
        }
        if(up[i][j]>1 && left[i][j]>1)
        {
          int half = up[i][j]/2;
          if(half > 1)
            count += min(half,left[i][j]) -1; 
          half = left[i][j]/2; 
          if(half > 1) 
            count += min(half,up[i][j]) -1;
        }
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



