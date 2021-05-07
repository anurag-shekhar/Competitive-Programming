
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll solve(int n,string origin,  vector<vector<string> > &A) {
    ll count = 0;
    map<string, int> m;
    m["INDIAN"] = 200;
    m["NON_INDIAN"] = 400;
    m["CONTEST_HOSTED"] = 50;
    m["TOP_CONTRIBUTOR"] = 300;
    m["CONTEST_WON"] = 300;

    for(int i =0; i<n; i++)
    {
        if(A[i][0] == "CONTEST_WON")
        {
          int x = stoi(A[i][1]);
          if(x<=20)
            count += m[A[i][0]] + 20 - x ;
          else   
            count += m[A[i][0]];
        }
        else if(A[i][0] == "BUG_FOUND")
            count += stoi(A[i][1]);
        else
            count += m[A[i][0]];
    }
    return count/m[origin];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int t = 1;
    cin >> t;
    while(t--) {
      int activities;
      string origin;
      cin>>activities>>origin;
      vector<vector<string> > A(activities,vector<string> (2));
      for(int i = 0;i<activities;i++)
      {
          cin>>A[i][0];
          if(A[i][0] == "CONTEST_WON" || A[i][0] == "BUG_FOUND")
            cin>>A[i][1];  

      }  
      cout<<solve(activities,origin, A)<<endl;
    }

    return 0;
}