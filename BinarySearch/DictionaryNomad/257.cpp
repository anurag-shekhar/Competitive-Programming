/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : 257.cpp
 * Created on : Tue Jun 22 2021
 ****************************************************************
 */

int solve(vector<string>& dictionary, string start, string end) {
    unordered_set<string> s;

    for(auto d : dictionary)
    {
        s.insert(d);
    }

    queue<pair<string, int> > q;
    q.push({start,1}); 
    s.erase(start);
    while(!q.empty())
    {
        pair<string, int> p = q.front();
        q.pop();

        if(p.first == end)
            return p.second;

        for(int i = 0; i<p.first.size(); i++)
        {
            string local = p.first; 
            for(char c = 'a'; c<='z'; c++)
            {
                local[i] = c;
                if(s.count(local))
                {
                    s.erase(local);
                    q.push({local, p.second+1});
                }
                
            }
        }
    }
    return -1;


}
