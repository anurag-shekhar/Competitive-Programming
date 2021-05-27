/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MaximumProductOfWordLengths_bitmasking.cpp
 * Created on : Thu May 27 2021
 ****************************************************************
 */

class Solution {
public:
    int maxProduct(vector<string>& words) {
    
        int n = words.size();
        vector<int> mask(n,0);
        for(int i = 0; i<n; i++)
        {
            for(char ch : words[i])
                mask[i] |= (1<<(ch-'a'));
        }
        
        int res = 0;
        for(int i = 0; i<n-1; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                if((mask[i]&mask[j]) == 0)
                    res = max(res, (int)(words[i].size() * words[j].size()));
            }
        }
        return res;
    }
};
