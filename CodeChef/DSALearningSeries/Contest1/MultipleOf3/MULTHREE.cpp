#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

string solve(ll K, int a, int b)
{
    vector<int> v,A;
    A.push_back(a);
    A.push_back(b);
    while(1)
    {
      ll sum = accumulate(A.begin(), A.end(), 0)%10; 
      if(sum%2)
        A.push_back(sum);
      else 
      {
        v.push_back(sum);
        for(int i =0; i<3;i++)
        {
          int temp = accumulate(A.begin(), A.end(), 0) + accumulate(v.begin(),v.end(),0);
          temp %= 10;
          v.push_back(temp);
        }  
        break;
      } 
    }
    K = K-A.size();
    int rem = K%4;
    int remSum = 0;
    K = (K-rem)/4;
    K *= 20;
    //cout<<"#"<<v[0]<<v[1]<<v[2]<<v[3]<<endl;
    for(int i = 0; i<rem; i++)
      remSum += v[i];

    int startSum = accumulate(A.begin(), A.end(), 0); 

    ll check = (startSum%3 + remSum%3 + K%3)%3;
    if(check)
      return "NO"; 
    return "YES";  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll K;
      int a,b;
      cin>>K>>a>>b;
      cout<<solve(K,a,b)<<endl; 
    }

    return 0;
}
