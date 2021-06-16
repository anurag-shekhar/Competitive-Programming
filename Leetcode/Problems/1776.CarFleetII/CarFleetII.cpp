class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        
        int n = cars.size();
        if(n==0)
            return {};
  
        stack<int> ahead;
        vector<double> timeToDest(n, -1);
        
        for(int i = n-1; i>=0; i--)
        {
            while(!ahead.empty() && cars[i][1] <= cars[ahead.top()][1])
                ahead.pop();
            
            
            while(!ahead.empty())
            {
                double timeToCollide = (cars[ahead.top()][0] - cars[i][0])/(double)((cars[i][1] - cars[ahead.top()][1]));
                if(timeToDest[ahead.top()] == -1 || timeToCollide <= timeToDest[ahead.top()])
                {
                    timeToDest[i] = timeToCollide;
                    break;
                }
                ahead.pop();
            }
            ahead.push(i);
        }
        return timeToDest;
    }
};
