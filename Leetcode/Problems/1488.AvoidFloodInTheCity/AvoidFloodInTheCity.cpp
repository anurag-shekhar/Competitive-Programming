class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        vector<int> res;
        unordered_map<int, int> m;
        int n = rains.size();
        set<int> dryDays;
        for(int i = 0; i<n; i++)
        {
            if(rains[i]==0)
            {
                dryDays.insert(i);
                res.push_back(1);
            }
            else 
            {
                if(m.find(rains[i])==m.end())
                {
                    m[rains[i]] = i;
                }
                else 
                {
                    int lake = m[rains[i]];
                    auto itr = dryDays.lower_bound(lake);
                    if(itr==dryDays.end())
                        return {};
                    res[*itr] = rains[i];
                    m[rains[i]] = i;
                    dryDays.erase(itr);
                }
                res.push_back(-1);  
            }
        }
        return res;
    }
};
