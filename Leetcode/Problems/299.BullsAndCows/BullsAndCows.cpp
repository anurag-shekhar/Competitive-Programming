/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : BullsAndCows.cpp
 * Created on : Tue Jun 15 2021
 ****************************************************************
 */

class Solution {
public:
    string getHint(string secret, string guess) {
        
        unordered_map<char, int> m;
        
        for(auto c : guess)
            m[c]++;
        
        int n = secret.size();
        int cow = 0;
        int bull = 0;
        for(int i = 0; i<n; i++)
        {
            if(secret[i]==guess[i])
            {
                m[guess[i]]--;
                bull++;     
            }
        }
        
        for(int i = 0; i<n; i++)
        {
            if(secret[i]!=guess[i])
            {
                if(m[secret[i]] > 0)
                {
                    m[secret[i]]--;
                    cow++;
                }    
            }
        }       
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
