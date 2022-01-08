/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : AsteroidCollision.cpp
 * Created on : Sat Jan 08 2022
 ****************************************************************
 */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> s;
        
        int n = asteroids.size();
        vector<int> result;
        for(int i = 0; i<n; i++)
        {
            if(asteroids[i] > 0)
                s.push_back(asteroids[i]);
            else 
            {
                while(!s.empty() && s.back() < abs(asteroids[i]))
                    s.pop_back();
                if(s.empty())
                    result.push_back(asteroids[i]);
                else if(s.back() == abs(asteroids[i]))
                    s.pop_back();
            }
        }
        
        while(!s.empty())
        {
            result.push_back(s.front());
            s.pop_front();
        }
        return result;
        
    }
};
