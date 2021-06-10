/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 627.cpp
 * Created on : Thu Jun 10 2021
 ****************************************************************
 */

string solve(string A, int k) {
    
    int n = A.size();
    deque<vector<char> > dq;
    for(int i = 0; i<n; i++)
    {
        if(dq.empty() || dq.back()[0] != A[i])
            dq.push_back({A[i]});
        else if(dq.back()[0]==A[i])
            dq.back().push_back(A[i]);
        
        if(dq.back().size()==k)
            dq.pop_back();
    }

    string res = "";
    while(!dq.empty())
    {
        vector<char> v = dq.front();
        dq.pop_front();

        for(char a : v)
            res += a;
    }
    return res;


}
