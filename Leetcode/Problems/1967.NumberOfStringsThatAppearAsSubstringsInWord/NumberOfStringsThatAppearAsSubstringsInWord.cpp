/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : NumberOfStringsThatAppearAsSubstringsInWord.cpp
 * Created on : Sun Aug 15 2021
 ****************************************************************
 */

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        
        
        unordered_set<string> s;
        
        int n = word.size();
        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<=n; j++)
            {
                s.insert(word.substr(i,j-i));
            }
        }
        
        int count = 0;
        for(string p : patterns)
            if(s.count(p))
                count++;
        return count;
    }
};
