/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : UniqueLength3PalindromicSubsequences.cpp
 * Created on : Sun Jul 11 2021
 ****************************************************************
 */

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        map<int, set<int> > idx;
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            idx[s[i]-'a'].insert(i);
        }
        int count = 0;
        for(int i = 0;i<26; i++)
        {
            auto itr1 =  idx[i].upper_bound(-1);
            if(itr1!=idx[i].end())
            {
                int findIdx2 = *itr1;
                for(int j = 0; j<26; j++)
                {
                    auto itr2 =  idx[j].upper_bound(findIdx2);
                    if(itr2!=idx[j].end())
                    {
                        int findIdx3 = *itr2;
                        auto itr3 =  idx[i].upper_bound(findIdx3);
                        if(itr3!=idx[i].end())
                        {
                            count++;
                        }
                            
                    }
                    
                }
            }
            
        }
        return count;
    }
};
