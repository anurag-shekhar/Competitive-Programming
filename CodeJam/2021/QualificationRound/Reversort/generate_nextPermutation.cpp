#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
//#include <algorithm>

using namespace std;

typedef long long int ll;

int fact(int n)
{
    if(n == 1 || n == 0)
        return 1;
    return n*fact(n-1);    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 1; i<=n; i++)
        v.push_back(i);

    int k = fact(n);
    cout<<k<<endl;
    while(k--)
    {
        cout<<n<<endl;
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
        next_permutation(v.begin(),v.end());    
    }
    return 0;
}
