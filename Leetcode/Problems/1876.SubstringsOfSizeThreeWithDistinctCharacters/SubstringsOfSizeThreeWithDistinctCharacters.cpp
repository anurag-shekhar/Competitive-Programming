/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SubstringsOfSizeThreeWithDistinctCharacters.cpp
 * Created on : Sun May 30 2021
 ****************************************************************
 */

class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int count = 0;
        int n = s.size();
        unordered_map<char, int> m;
        for(int i = 0; i<n; i++)
        {
            if(i<3)
                m[s[i]]++;
            else 
            {
                m[s[i-3]]--;
                if(m[s[i-3]]==0)
                    m.erase(s[i-3]);
                m[s[i]]++;
            }
            if(m.size()==3)
                count++;
        }
        return count;
            
            
            
    }
};

/*
0 1 2 3 4 5
^   ^
*/
