/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : SearchSuggestionsSystem.cpp
 * Created on : Mon May 31 2021
 ****************************************************************
 */

class Trie
{
    public: 
    char ch;
    vector<string> store;
    vector<Trie*> next;
    Trie(char c): ch(c), next(vector<Trie*> (26,NULL)){}
};
Trie* insert(Trie* root, string s, int idx)
{
    if(s.size()==idx)
        return root;
    if(!root->next[s[idx]-'a'])
        root->next[s[idx]-'a'] = new Trie(s[idx]); 
    if(root->next[s[idx]-'a']->store.size() < 3)
        root->next[s[idx]-'a']->store.push_back(s);

    insert(root->next[s[idx]-'a'], s,idx+1);
    return root;
}
vector<string> findPrefix(Trie* root, string s, int currIdx, int idx)
{
    if(!root->next[s[currIdx]-'a'])
        return {};
    
    if(currIdx == idx)
        return root->next[s[currIdx]-'a']->store;

    return findPrefix(root->next[s[currIdx]-'a'], s,currIdx+1, idx);
}
class Solution {
public:

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        Trie* root = new Trie('#');
        sort(products.begin(), products.end());
        
        for(string s : products)
            root = insert(root, s,0);
            
        
        int n = searchWord.size();
        vector<vector<string> > res;
        for(int i = 0; i<n; i++)
            res.push_back(findPrefix(root, searchWord,0, i));
        return res;
    }
};
