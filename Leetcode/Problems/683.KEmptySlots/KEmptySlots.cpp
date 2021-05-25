/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : KEmptySlots.cpp
 * Created on : Tue May 25 2021
 ****************************************************************
 */

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        
        set<int> s;
        int n = bulbs.size();
        for(int i =0; i<n; i++)
        {
            s.insert(bulbs[i]);
            
            auto itr = s.find(bulbs[i]);
            
            auto p_itr = itr;
            auto n_itr = itr;
            if(itr!=s.begin())
            {
                p_itr = prev(itr);
                
                if((*itr - *p_itr - 1) == k)
                    return i+1;
            }
                
            n_itr =next(itr);
            if(n_itr!=s.end())
            {
                if((*n_itr - *itr - 1) == k)
                    return i+1;   
            }
            
        }
        return -1;
    }
};
