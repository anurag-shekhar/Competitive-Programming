/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : JumpGameVII.cpp
 * Created on : Tue May 25 2021
 ****************************************************************
 */

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.size();
        if(s[n-1]=='1')
            return false;
        unordered_set<int> cache;
        queue<int> q;
        q.push(0);
        cache.insert(0);
        
        while(!q.empty())
        {
            int idx = q.front();
            q.pop();
            
            for(int i = maxJump + idx; i>= minJump + idx; i--)
            {
                if(i==n-1)
                    return true;
                if(i<n && s[i]=='0' && cache.count(i)==0)
                    cache.insert(i), q.push(i);
            }
        }
        return false;
    }
};
