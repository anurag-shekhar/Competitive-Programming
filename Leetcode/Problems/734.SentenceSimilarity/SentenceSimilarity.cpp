/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SentenceSimilarity.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

class Solution {
public:
    

    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
        int s1 = sentence1.size();
        int s2 = sentence2.size();
        
        if(s1!=s2)
            return false;
        set<vector<string> > m;
        
        for(auto a : similarPairs)
        {
            m.insert(a);
        }
        
        for(int i = 0; i<s1; i++)
        {
            if(sentence1[i] == sentence2[i] || m.count({sentence1[i], sentence2[i]}) || m.count({sentence2[i], sentence1[i]}))
               continue;
            else 
                return false;
        }
        return true;;
        
    }
};



