#define ll long long int
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        vector<int> res;
        int psize = points.size(), qsize = queries.size();
        for(int i = 0; i<qsize; i++)
        {
            int count =0;
            
            for(int j = 0; j<psize; j++)
            {
                ll pointTest = ((points[j][0] - queries[i][0])*(points[j][0] - queries[i][0])) + ((points[j][1] - queries[i][1])*(points[j][1] - queries[i][1]));
                
                ll radius = (queries[i][2]*queries[i][2]);
                if(pointTest <= radius)
                    count++;
            }
            res.push_back(count);
        }
        return res;
    }
};
