#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long int ll;

void reverse(vector<ll> &A, int i ,int j)
{
    while (i<j)
    {
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
      i++;
      j--;
    }   
}

bool solve(ll n,vector<ll> &A,ll idx,int sum) {

        if(sum == 0 && idx == -1)
        {
          return true;
        }
        if(idx==-1)
          return false;
        for(int i = idx; i<n; i++)
        {
          reverse(A,idx,i);
          if(solve(n,A,idx-1,sum - (i-idx+1)))
            return true;
          reverse(A,idx,i);  
        } 
        return false; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    int T = t;
    while(t--) {
      ll n,sum;
      cin>>n>>sum;
      vector<ll> A;
      for(int i = 1; i<=n; i++)
        A.push_back(i);
      cout<<"Case #"<<T-t<<": ";

      int maxSum = (n*(n+1)/2)-1;
      int minSum = n-1;
      if(sum < minSum || sum > maxSum)
        cout<<"IMPOSSIBLE";
      else if(solve(n,A,n-2,sum))
      {
        for(int a : A)
          cout<<a<<" ";
      }
      else 
        cout<<"IMPOSSIBLE";
      cout<<endl;  
    }

    return 0;
}
