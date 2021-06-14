/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : VerifyingAlienDictionary.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char, int> m;
        
        for(int i = 0; i<order.size(); i++)
            m[order[i]] = i;
        
        int n = words.size();
        for(int i = 0; i<n-1; i++)
        {
            for(int j = 0; j<words[i].size(); j++)
            {
                if(j==words[i+1].size())
                    return false;
                if(words[i][j] != words[i+1][j])
                {
                    if(m[words[i][j]] > m[words[i+1][j]])
                        return false;
                    break;
                }
            }
        }
        return true;
    }
};
