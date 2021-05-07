#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

string solve(string &s) {
    int n = s.size();
    vector<int> left(26,0);
    vector<int> right(26,0);

    for(int i = 0; i<n/2; i++)
    {
        left[s[i]-'a']++;
        right[s[n-i-1]-'a']++;
    }

    for(int i = 0; i<26; i++)
    {
        if(left[i]!=right[i])
            return "NO";
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }

    return 0;
}