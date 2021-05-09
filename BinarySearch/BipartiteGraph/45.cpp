/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 45.cpp
 * Created on : Sun May 09 2021
 ****************************************************************
 */

bool solve(vector<vector<int>>& graph) {
    
    int n = graph.size();
    unordered_set<int> visited;
    unordered_set<int> A[2];

    for(int i = 0; i < n; i++)
    {
        if(visited.find(i)==visited.end())
        {
            queue<pair<int,int> > q;
            q.push({i,0});
            while(!q.empty())
            {
                pair<int,int> p = q.front();
                q.pop();
                visited.insert(p.first);

                if(A[(p.second+1)%2].find(p.first) != A[(p.second+1)%2].end())
                    return false;
                A[p.second].insert(p.first);

                for(int a : graph[p.first])
                {
                    if(visited.find(a)==visited.end())
                        q.push({a,(p.second+1)%2});
                }
            }
        }
    }
    return true;


}

/*
 0 : 2,3
 1 : 2,3
 2 : 1,0
 3 : 1,0


 0 1     |.     2 3  

 0 : 1,2,3
 1 : 0,2
 2 : 0,1,3
 3 : 0,2


 0.   |.    1 2 3


*/
