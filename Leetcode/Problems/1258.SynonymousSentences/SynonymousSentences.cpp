/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SynonymousSentences.cpp
 * Created on : Fri May 28 2021
 ****************************************************************
 */


class Solution {
public:
    unordered_map<string, vector<string> > m;
    
    void dfs(string temp, set<string> &possible)
    {
        if(possible.count(temp))
            return;
        possible.insert(temp); 
        for(string a : m[temp])
            dfs(a, possible);
    }
    
        
    void generate(string text, int idx, string builder, vector<string> &res)
    {
        if(idx==text.size())
        {
            res.push_back(builder);
            return;
        }
        if(text[idx]==' ')
            return generate(text, idx+1, builder + " ", res);
        else 
        {
            string temp = "";
            while(idx<text.size() && isalpha(text[idx]))
                temp+=text[idx++];
            idx--;
            
            set<string> possible;
            dfs(temp, possible);
            
            for(string a : possible)
                generate(text, idx+1, builder+a, res);
        }
    }
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        
        vector<string> res;
        m.clear();
        for(auto a : synonyms)
        {
            m[a[0]].push_back(a[1]);
            m[a[1]].push_back(a[0]);
        }
        generate(text, 0, "", res);
        return res;
        
        
    }
};
