/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ExpressiveWords.cpp
 * Created on : Wed May 12 2021
 ****************************************************************
 */

class Solution {
public:
    bool checkExpressive(vector<pair<char, int> > &s_freq, string word)
    {
        vector<pair<char, int> > word_freq;
        for(int i = 0; i<word.size(); i++)
        {
            int localCount = 1;
            while(i+1<word.size() && word[i] == word[i+1])
            {
                localCount++;
                i++;
            }
            word_freq.push_back(make_pair(word[i],localCount));
        }
        
        if(word_freq.size() != s_freq.size())
            return false;
        
        for(int i = 0; i<s_freq.size(); i++)
        {
            if(s_freq[i].first != word_freq[i].first)
                return false;
            if(s_freq[i].second < word_freq[i].second)
                return false;
            if(s_freq[i].second!=word_freq[i].second && s_freq[i].second < 3))
                return false;
        }
        return true;
        
        
    }
    int expressiveWords(string s, vector<string>& words) {
        
        int count = 0;
        vector<pair<char, int> > s_freq;
        for(int i = 0; i<s.size(); i++)
        {
            int localCount = 1;
            while(i+1<s.size() && s[i] == s[i+1])
            {
                localCount++;
                i++;
            }
            s_freq.push_back(make_pair(s[i],localCount));
        }
        
        for(string word : words)
            if(checkExpressive(s_freq,word))
                count++;
        return count;
        
    }
};
