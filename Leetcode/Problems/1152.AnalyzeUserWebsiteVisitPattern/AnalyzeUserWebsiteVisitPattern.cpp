/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AnalyzeUserWebsiteVisitPattern.cpp
 * Created on : Wed Jul 28 2021
 ****************************************************************
 */

class Solution {
public:
    static bool compare(pair<string, int> &a, pair<string, int> &b)
    {
        if(a.second > b.second || (a.second == b.second && a.first < b.first))
           return true;
        return false;
    }
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        
        map<string, map<int, string> > m;
        map<string, int> count;
        
        int n = username.size();
        for(int i =0; i<n; i++)
        {
            m[username[i]][timestamp[i]] = website[i];
        }
        
        for(auto str_map : m)
        {
            vector<string> v; // Make iteration easy
            for(auto int_str : str_map.second)
                v.push_back(int_str.second);
            
            n = v.size();
            
            set<string> s;  //IMPORTANT
            for(int i = 0; i<n-2; i++)
            {
                for(int j = i+1; j<n-1; j++)
                {
                    for(int k = j+1; k<n; k++)
                    {
                        s.insert(v[i]+ "-" + v[j] + "-" + v[k]);   
                    }
                }
            }
            for(auto str : s)
                count[str]++;
        }
        
        vector<pair<string, int> > res;
        for(auto p : count)
            res.push_back(p);
        sort(res.begin(), res.end(), compare);
        
        vector<string> final_res;
        string temp = "";
        for(char ch : res[0].first)
        {
            if(ch == '-')
            {
                final_res.push_back(temp);
                temp = "";
            }
            else
                temp += ch;
        }
        final_res.push_back(temp);
        return final_res;
    }
};
