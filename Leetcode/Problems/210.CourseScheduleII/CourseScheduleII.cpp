/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : CourseScheduleII.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
         vector<vector<int> > preReq(numCourses);
        vector<int> degree(numCourses,0);
        queue<int> q;
        
        for(int i = 0; i<prerequisites.size(); i++)
        {
            preReq[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        unordered_set<int> visited;
        for(int i = 0; i<numCourses; i++)
        {
            visited.insert(i);
            if(degree[i]==0)
            {
                visited.erase(i);
                q.push(i);
            }
               
        }
        vector<int> res;
        while(!q.empty())
        {
            int n = q.front();
            q.pop();
            
            for(int a : preReq[n])
            {
                degree[a]--;
                if(degree[a]==0)
                {
                   visited.erase(a); 
                   q.push(a); 
                }   
            }
            res.push_back(n);
        }
        
        if(visited.size()==0)
            return res;
        return {};
    }
};
