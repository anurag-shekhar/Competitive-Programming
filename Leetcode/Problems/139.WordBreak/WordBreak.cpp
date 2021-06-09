/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : WordBreak.cpp
 * Created on : Wed Jun 09 2021
 ****************************************************************
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(string word : wordDict)
            dict.insert(word);
        int n = s.size();
        vector<bool> dp(n);
        vector<int> wordBreakIdx;
        wordBreakIdx.push_back(-1);
        for(int i = 0; i<n; i++)
        {
            for(int idx : wordBreakIdx)
            {
                if(dict.count(s.substr(idx+1,i-idx)))
                {
                    wordBreakIdx.push_back(i);
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};
