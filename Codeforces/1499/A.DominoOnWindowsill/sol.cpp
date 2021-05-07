#include<bits/stdc++.h>
using namespace std;
//=======================


string solve(int n, int k1, int k2, int w, int b) {
    int left, right, mid;

    left = min(k1,k2);
    mid = max(k1,k2) - min(k1,k2);
    right = n - max(k1,k2);

    w -= left;
    b -= right;

    if(mid%2 == 1)
      mid--;
    mid = mid/2;  
    w-=mid;
    b-=mid;
    
    if(w<=0 && b<=0)
      return "YES";
    else 
      return "NO"; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      int n, k1, k2,w, b;
      cin>>n>>k1>>k2>>w>>b;
      cout<<solve(n,k1,k2,w,b)<<endl;
    }

    return 0;
}
