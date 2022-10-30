/*
 ***************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 * 
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 * 
 * File Name : WordsWithinTwoEditsOfDictionary.cpp
 * Created on : Sun Oct 30 2022 
 ***************************************************************
 */

class Solution {
public:
    
    bool twoEditsAway(string s, string base) {
        
        int n = s.size();
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(s[i]!=base[i]) {
                count++;
                if(count==3)
                    return false;
            }                
        }
        return true;
    }
    
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        
        vector<string> result;
        for(string q : queries)
        {
            for(string d : dictionary)
            {
                if(twoEditsAway(q,d)) {
                    result.push_back(q);      
                    break;
                }
            }
        }
        return result;
    }
};
