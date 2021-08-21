/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : MinimumTimetoTypeWordUsingSpecialTypewriter.cpp
 * Created on : Sat Aug 21 2021
 ****************************************************************
 */

class Solution {
public:
    int minTimeToType(string word) {
        
        
        unordered_map<char, vector<int> > m;
        
        char ch = 'a';
        for(int i = 0; i<26; i++, ch++)
        {
            m[ch] = {i,26+i};
        }
        
        int n = word.size();
        int time = 0;
        word = 'a' + word;
        for(int i = 1; i<n+1; i++)
        {
            int clock = min(abs(m[word[i]][1] - m[word[i-1]][0]), abs(m[word[i]][1] - m[word[i-1]][1]) );
            int anti = min(abs(m[word[i]][0] - m[word[i-1]][0]), abs(m[word[i]][0] - m[word[i-1]][1]) );

            time += min(anti, clock);
            time++;
        }
        return time;
    }
};
