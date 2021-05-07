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
ll reversort(ll n,  vector<ll> A) {
    ll sum = 0;

    for(int i = 0; i<n-1; i++)
    {
        int minVal = INT_MAX, minIdx=1;; 
        for(int j = i; j<n; j++)
        {
            if(minIdx == -1 || minVal > A[j])
            {
              minIdx = j;
              minVal = A[j];
            } 
        }       
            // for(int a : A)
            //   cout<<a<<" ";
            // cout<<endl;  
            reverse(A,i,minIdx);
            sum += max(minIdx-i+1,0);
        
    }
    return sum;
}

bool solve(ll n,vector<ll> &A,ll idx,int sum) {

    while(1)
    {
        if(sum == reversort(n,A))
            return true;
        else 
            next_permutation(A.begin(),A.end());       
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
