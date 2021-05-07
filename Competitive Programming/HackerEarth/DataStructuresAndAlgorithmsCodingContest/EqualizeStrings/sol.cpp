#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
void swap(string &A, int i, int j)
{
  char ch = A[i];
  A[i] = A[j];
  A[j] = ch;
}

ll solve(ll n,  string &A, string &B) {
    ll count = 0;

    //cout<<A<<" "<<B<<endl;
    for(int i = 0; i<n; i++)
    {
      if(i!=n-1 && A[i]!=B[i] && A[i+1] != B[i+1] && A[i]!=A[i+1])
      {
        swap(A,i,i+1);
        i++;
        count++;
      }
      else if(A[i]!=B[i])
      {
        A[i] = B[i];
        count++;
      }
    }
    //cout<<A<<" "<<B<<endl;
    return count;
}

int main() {
    
    DND;
	
    int t = 1;
    while(t--) {
      ll n;
      cin>>n;
      string A,B;
      cin>>A>>B;
      cout<<solve(n,A,B)<<endl;
    }

    return 0;
}
