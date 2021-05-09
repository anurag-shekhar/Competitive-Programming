

class Solution {
public:
    static bool compare1(vector<int> &a, vector<int> &b)
    {
        if(a[2] > b[2] )
            return true;
        return false;
    }
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if(a[0] < b[0] )
            return true;
        return false;
    }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        for(int i = 0; i<n ; i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(), compare);
        map<int, vector<vector<int> > > m;
        vector<int> res;
    
        int time = 0; 
        for(int i = 0; i<n; i++)
        {

            if(time > tasks[i][0])
            {
                m[tasks[i][1]].push_back(tasks[i]);
                continue;
            }
            else 
            {
                if(m.size()==0 || time==tasks[i][0])
                {
                    if(m.size()==0)
                    {
                        m[tasks[i][1]].push_back(tasks[i]);
                        time = tasks[i][0];
                        i++;
                    }    
                    while(i<n && time==tasks[i][0])
                    {
                        m[tasks[i][1]].push_back(tasks[i]);
                        i++;
                    }
                    i--;
                }
                else 
                    i--;
                sort(m.begin()->second.begin(), m.begin()->second.end(),compare1);
                vector<int> check = m.begin()->second.back();
                m.begin()->second.pop_back();
                if(m.begin()->second.size()==0)
                    m.erase(m.begin());
                time = max(time,check[0]) + check[1];
                res.push_back(check[2]);
            }
        }
        
        while(m.size()!=0)
        {
            sort(m.begin()->second.begin(), m.begin()->second.end(),compare1);
            vector<int> check = m.begin()->second.back();
            m.begin()->second.pop_back();
            if(m.begin()->second.size()==0)
                m.erase(m.begin());
            time = check[0] + check[1];
            res.push_back(check[2]);
        }
        
        return res;
    }
};
/*
[[1,2],[2,4],[3,2],[4,1]]
   
[[19,13],[16,9],[21,10],[32,25],[37,4],[49,24],[2,15],[38,41],[37,34],[33,6],[45,4],[18,18],[46,39],[12,24]]
   [6,1,2,9,4,10,0,11,5,13,3,8,12,7]
   
   
[[35,36],[11,7],[15,47],[34,2],[47,19],[16,14],[19,8],[7,34],[38,15],[16,18],[27,22],[7,15],[43,2],[10,5],[5,4],[3,11]]
    [15,14,13,1,6,3,5,12,8,11,9,4,10,7,0,2]

*/


