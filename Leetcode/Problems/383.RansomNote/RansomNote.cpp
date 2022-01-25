/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : RansomNote.cpp
 * Created on : Tue Jan 25 2022
 ****************************************************************
 */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> HashMap;
        int charLeft = 0;
        int n = ransomNote.size();
        int m = magazine.size();
        for(int i = 0; i<n; i++)
        {
            HashMap[ransomNote[i]]++;
            if(HashMap[ransomNote[i]] == 1)
                charLeft++;
        }
        for(int i = 0; i<m; i++)
        {
            HashMap[magazine[i]]--;
            if(HashMap[magazine[i]] == 0)
                charLeft--;
        }
        return charLeft == 0;
    }
};
