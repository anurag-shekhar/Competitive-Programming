class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
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
        }
        
        if(visited.size()==0)
            return true;
        return false;
            
        
        
        
    }
};
