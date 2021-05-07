#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

string solve(string &A) {

    stack<char> s;

    for(int i = 0; i<A.size(); i++)
    {
      if(A[i]!='\\')
        s.push(A[i]);
      else
      {
        string temp = "";
        while(s.top()!='/')
        {
          temp+=s.top();
          s.pop();
        }
        s.pop();
        for(char ch : temp)
          s.push(ch);
      }  
    }
    string temp = "";
    while(!s.empty())
    {
      temp+=s.top();
      s.pop();
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int main() {
    
    DND;
	
    int t = 1;
    while(t--) {
      string s;
      cin>>s;

      cout<<solve(s)<<endl;
    }

    return 0;
}
