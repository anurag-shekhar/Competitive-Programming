/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : KeysAndRooms.cpp
 * Created on : Sun May 23 2021
 ****************************************************************
 */

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> visited;
        unordered_set<int> keys;
        queue<int> q;
        q.push(0);
        keys.insert(0);
        
        while(!q.empty())
        {
            int roomNumber = q.front();
            q.pop();
            
            visited.insert(roomNumber);
            for(int k : rooms[roomNumber])
            {
                if(keys.count(k)==0 && visited.count(k)==0)
                {
                    q.push(k);
                }
            }
        }
        return visited.size()==n;
    }
};
