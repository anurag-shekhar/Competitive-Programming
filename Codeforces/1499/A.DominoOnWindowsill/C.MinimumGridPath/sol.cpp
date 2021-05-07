#include<bits/stdc++.h>
using namespace std;
//=======================


int solve(int n, vector<int> &cost) {

  int idxR=-1,idxC = -1;
  int valR=INT_MAX, valC = INT_MAX;

  int minCost = 0;
  for(int i=0,j=1; j<n; j+=2,i+=2)
  {
    if(valR>cost[i])
    {
      idxR = i;
      valR = cost[i];
    }
    if(valC>cost[j])
    {
      idxC = j;
      valC = cost[j];
    }
  }

  int totR = n,totC=n;
  for(int i=0; i<n; i+=2)
  {
    if(i==idxR)
    {
      minCost += totR*cost[i];
    }
    minCost += cost[i];
    totR--;
  }
  for(int j=1; j<n; j+=2)
  {
    if(j==idxR)
    {
      minCost += totC*cost[j];
    }
    minCost += cost[j];
    totC--;
  } 
  return minCost;

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      int n;
      vector<int> cost[n];
      for(int i = 0;i<n;i++)
        cin>>cost[i];
      cout<<solve(n,cost)<<endl;
    }

    return 0;
}
