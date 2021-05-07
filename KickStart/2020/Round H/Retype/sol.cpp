#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,T;
    cin>>t;
    T=t;
    while(t--)
    {
        int n,k,s;
        cin>>n>>k>>s;
        cout<<"Case #"<<T-t<<": "<<k-1+min(n+1,(k-s)+(n-s+1))<<endl;
    }
    return 0;
}
