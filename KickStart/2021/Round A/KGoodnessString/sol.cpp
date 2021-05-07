#include<bits/stdc++.h>
using namespace std;



int solve(int n,int k,string &s) {

    int matched = 0;
    int mismatched = 0;
    for(int i = 0; i<s.size()/2; i++)
    {
        int corr_i = n-i-1;
        if(s[i]==s[corr_i])
          matched++;
        else 
          mismatched++;
    }
    return abs(k-mismatched);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t ,T;
    cin >> t;
    T=t;
    while(t--) {
      int n,k;
      string s;
      cin>>n>>k>>s;
      cout<<"Case #"<<T-t<<": "<<solve(n,k,s)<<endl;
    }

    return 0;
}


