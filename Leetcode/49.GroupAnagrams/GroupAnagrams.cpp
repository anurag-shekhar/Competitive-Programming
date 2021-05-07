class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
         vector<vector<string>> res;
        vector<string> A = strs;
        for(int i = 0;i<n; i++)
        {
            sort(A[i].begin(), A[i].end());
        }
        unordered_map<string,vector<int> > m;
        
        for(int i = 0;i <n; i++)
        {
            m[A[i]].push_back(i);
        }
        
        for(pair<string, vector<int>> mi : m)
        {
            vector<string> v;
            for(int i : mi.second)
                v.push_back(strs[i]);
            res.push_back(v);
        }
        return res;
        
        
            
        
    }
};
