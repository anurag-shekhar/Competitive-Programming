/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumNumberOfRemovableCharacters.cpp
 * Created on : Sun Jun 13 2021
 ****************************************************************
 */

class Solution {
public:
    
    
    bool checkSubseq(string s, string p, vector<int>& removable, int k)
    {
        
        int p_i = 0;
        int r_i = 0;
        vector<bool> removed(s.size(), false);
        
        for(int i = 0; i<k; i++)
            removed[removable[i]] = true;
        for(int i=0; i<s.size(); i++)
        {
            if(removed[i])
                continue;
            if(p[p_i] == s[i])
            {
                p_i++;
                if(p_i == p.size())
                    return true;
            }
        }
        return false;
        
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        
        int low = 0;
        int high = removable.size();
        
        int res = high;
        
        while(low<=high)
        {
            int mid = (high-low)/2 + low;
            
            if(checkSubseq(s,p,removable, mid))
            {
                res = mid;
                low = mid+1;
            }
            else 
                high = mid-1;
        }
        return res;
    }
};
