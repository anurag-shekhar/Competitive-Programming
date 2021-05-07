#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


class node
{
  public:
  int start;
  int end;
  int turn;
  node(int s, int e, int t):start(s), end(e), turn(t){}
};

pair<char, ll> solve(ll size,  string &s) {
    unordered_map<int,char> m;
    m[0] = 'O';
    m[1] = 'I';

    queue<node*> q;
    q.push(new node(0,size-1, 1));

    while(!q.empty())
    {
      node* n = q.front();
      q.pop();

      if(n->start > n->end)
        return make_pair(m[(n->turn+1)%2], 1);

      if(s[n->start] != m[n->turn] && s[n->end]!= m[n->turn])
        return make_pair(m[(n->turn+1)%2], n->end - n->start+2);

      if(s[n->start] == m[n->turn])
        q.push(new node(n->start+1, n->end, (n->turn+1)%2));

      if(s[n->end] == m[n->turn])
        q.push(new node(n->start, n->end-1,(n->turn+1)%2 ));    
    }
    
    return make_pair('I',1);
}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    int T = t;
    while(t--) {
      string s;
      cin>>s;
      int n = s.size();
      pair<char, ll> p = solve(n,s);  
      cout<<"Case #"<<T-t<<": "<<p.first<<" "<<p.second<<endl;
    }

    return 0;
}
