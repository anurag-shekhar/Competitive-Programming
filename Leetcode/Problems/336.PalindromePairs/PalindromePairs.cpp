/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : PalindromePairs.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */

class Solution {
public:
    
    bool isPalin(string word)
    {
        int l = 0, r = word.size()-1;
        
        while(l<=r)
        {
            if(word[l]!=word[r])
                return false;
            l++;
            r--;
        }
        return true;
        
    }
    string reverseWord(string word)
    {
        string temp = word;
        reverse(temp.begin(), temp.end());
        return temp;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        
        unordered_map<string, int> m;
        int n = words.size();
        for(int i = 0; i<n; i++)
        {
            m[words[i]] = i;
        }
        
        vector<vector<int> > res;
        
        //handling empty string 
        if(m.count(""))
        {
            int idx = m[""];
            for(int i = 0; i<n; i++)
            {
                string currWord = words[i];

                //concatenation with empty string
                if(idx != m[currWord] && isPalin(currWord))
                {
                    res.push_back({idx, i});
                    res.push_back({i, idx});
                }
            }
        }
        
        for(int i = 0; i<n; i++)
        {
            string revWord = reverseWord(words[i]);
            // same length case 
            if(m.count(revWord))
            {
                int idx = m[revWord];
                if(idx!=i)
                    res.push_back({i,idx});
            }
            
            //word1 with shorter length 
            for(int cut = 1; cut<words[i].size(); cut++)
            {
                string left = words[i].substr(0,cut);
                string right = words[i].substr(cut); 
                
                string revRight = reverseWord(right);
                if(isPalin(left) && m.count(revRight) && m[revRight]!=i)
                    res.push_back({m[revRight],i});
            }
            //word1 with longer length 
            for(int cut = words[i].size()-1; cut>0; cut--)
            {
                string left = words[i].substr(0,cut);
                string right = words[i].substr(cut); 
                
                string revLeft = reverseWord(left);
                if(isPalin(right) && m.count(revLeft) && m[revLeft]!=i)
                    res.push_back({i ,m[revLeft]});
            }
        }
        
        return res;
        
        
        
            
        
        
    }
};
