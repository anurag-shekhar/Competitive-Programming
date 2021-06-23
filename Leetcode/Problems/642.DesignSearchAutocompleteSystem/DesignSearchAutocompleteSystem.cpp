/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DesignSearchAutocompleteSystem.cpp
 * Created on : Wed Jun 23 2021
 ****************************************************************
 */

class AutocompleteSystem {
public:
    class trie
    {
        public:
        char ch;
        vector<trie*> child;
        unordered_map<string, int> m;
        
        trie(char c) : ch(c), child(vector<trie*>(128,NULL)) {}
    };
    
    void insert(trie* root, string s, int idx, int times)
    {
        if(idx == s.size())
            return;
        if(!root->child[s[idx]])
            root->child[s[idx]] = new trie(s[idx]);
        
        root->child[s[idx]]->m[s] += times;
        insert(root->child[s[idx]], s, idx+1, times);
    }
    
    pair<trie*, unordered_map<string, int> > search(trie* root, char c)
    {
        if(!root || !root->child[c])
            return {NULL, {}};
        return {root->child[c], root->child[c]->m};
    }
    
    trie* root;
    trie* currNode;
    string currString;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        currString= "";
        root = new trie('*');
        currNode = root;
        
        for(int i = 0; i<times.size(); i++)
        {
            insert(root, sentences[i], 0, times[i]);
        }
    }
    
    static bool compare(pair<string , int> a, pair<string , int> b)
    {
        if(a.second > b.second || (a.second == b.second && a.first < b.first ) )
            return true;
        return false;
    }
    vector<string> input(char c) {
 
        if(c == '#')
        {
            insert(root, currString, 0,1);
            currString = "";
            currNode = root;
            return {};
        }
        currString += c;
        pair<trie*, unordered_map<string, int> > p = search(currNode, c);
        
        currNode = p.first;
        vector<pair<string, int> > v;
        
        for(auto a : p.second)
        {
            v.push_back({a.first, a.second});
        }
            
        sort(v.begin(), v.end(), compare);
        
        vector<string> res;
        int n = v.size();
        for(int i = 0; i<min(3,n); i++)
            res.push_back(v[i].first);
        return res;
            
        
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
