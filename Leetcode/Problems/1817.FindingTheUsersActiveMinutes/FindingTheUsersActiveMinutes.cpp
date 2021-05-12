/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FindingTheUsersActiveMinutes.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
     
        unordered_map<int,unordered_set<int> > m;
        for(vector<int> i : logs)
        {
            m[i[0]].insert(i[1]);
        }
        
        vector<int> answer(k,0);
        
        for(pair<int,unordered_set<int> > p : m)
        {
            //cout<<p.first<<" "<<p.second.size()<<endl;
            answer[p.second.size()-1]++;
        }
        return answer;
    }
};
