/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : FruitIntoBaskets.cpp
 * Created on : Tue May 25 2021
 ****************************************************************
 */

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        
        unordered_map<int,int> m;
        
        int n = tree.size();
        
        int left = 0, right = 0;
        
        int res = 0;
        while(right<=n)
        {
            if(m.size()<=2)
            {
                if(right==n)
                    break;
                m[tree[right]]++;
                right++;
                if(m.size()<=2)
                    res = max(res, right-left);
            }
            else 
            {
                m[tree[left]]--;
                if(m[tree[left]]==0)
                    m.erase(tree[left]);
                left++;
                    
            }
        }
        return res;
    }
};
