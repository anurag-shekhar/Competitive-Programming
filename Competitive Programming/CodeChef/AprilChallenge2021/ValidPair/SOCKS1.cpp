#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main() {
    
    DND;
	
    int t = 1;
    while(t--) {
      ll a,b,c;
      cin>>a>>b>>c;

      if(a==b || b==c || a==c)
          cout<<"YES"<<endl;
      else 
        cout<<"NO"<<endl;        
    }

    return 0;
}
