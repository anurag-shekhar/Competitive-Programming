/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : sol.cpp
 * Created on : Sat Jun 19 2021
 ****************************************************************
 */

#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long int
#define DND ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve(ll n,  vector<ll> &A) {
    
    sort(A.begin(), A.end());

    vector<ll> store;
    store.push_back(0);
    store.push_back(1);
    for(int i = 0; i<n-1; i++)
    {
        if(A[i+1] - A[i] < A[store[1]] - A[store[0]] )
        {
            store[0] = i;
            store[1] = i+1;
        }
    }

    cout<<A[store[0]]<<" ";

    for(int i = store[1]+1; i<n; i++)
        cout<<A[i]<<" ";
    for(int i = 0; i<store[0]; i++)
        cout<<A[i]<<" ";
    cout<<A[store[1]]<<endl;

}

int main() {
    
    DND;
	
    int t = 1;
    cin >> t;
    while(t--) {
      ll n;
      cin>>n;
      vector<ll> A(n);
      for(int i = 0;i<n;i++)
        cin>>A[i];
      solve(n,A);
    }

    return 0;
}