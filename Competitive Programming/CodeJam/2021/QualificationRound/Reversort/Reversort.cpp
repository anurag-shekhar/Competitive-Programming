#include<bits/stdc++.h>
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

ll solve(ll n,  vector<ll> &A) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    int T = t;
    while(t--) {
      ll n;
      cin>>n;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      cout<<"Case #"<<T-t<<": "<<solve(n,A)<<endl;
    }

    return 0;
}
