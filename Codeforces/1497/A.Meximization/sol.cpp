#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        multiset<int> s;
        int a;
        for(int i = 0;i<n;i++)
        {
            cin>>a;
            s.insert(a);    
        }
        for(int i = 0; i<n; i++)
        {
            auto itr = s.find(i);
            if(itr!=s.end())
            {
                cout<<i<<" ";
                s.erase(itr);
            }
            else 
            {
                for(auto i = s.begin(); i!=s.end(); i++)
                    cout<<*i<<" ";
                break;    
            }   
        }
        cout<<endl;
    }
}