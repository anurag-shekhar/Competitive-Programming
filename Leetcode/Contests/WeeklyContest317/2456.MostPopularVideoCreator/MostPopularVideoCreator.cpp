/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : MostPopularVideoCreator.cpp
 * Created on : Sun Oct 30 2022 
 ***************************************************************
 */

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        
        unordered_map<string, pair<string, vector<long> > > m;
        long maxViews = 0;
        int n = creators.size();
        for(int i = 0; i<n; i++) {
            if(m.find(creators[i]) == m.end()) {
                m[creators[i]] = {ids[i], {views[i],views[i]} };
                maxViews = max(maxViews, (long)views[i]);
            } else {
                m[creators[i]].second[0] += views[i];
                maxViews = max(maxViews, m[creators[i]].second[0]);
                if(m[creators[i]].second[1] < views[i] || (m[creators[i]].second[1] == views[i] && m[creators[i]].first > ids[i]) ) {
                    m[creators[i]].first = ids[i];
                    m[creators[i]].second[1] = views[i];
                    
                }
            }
        }
        
        vector<vector<string>> result;
        for(auto itr = m.begin(); itr != m.end(); itr++) {
            if(itr->second.second[0] == maxViews) {
                result.push_back({itr->first, itr->second.first});
            }
        }
        return result;
        
    }
};
