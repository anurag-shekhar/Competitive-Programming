/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DesignAddAndSearchWordsDataStructure_trie.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */


class WordDictionary {
public:
    /** Initialize your data structure here. */
    class trie
    {
        public:
        char ch;
        bool endHere;
        vector<trie*> child;
        
        trie(char c) : ch(c), endHere(false), child(vector<trie*> (26, NULL)) {}
    };
    trie* root;
    WordDictionary() {
        
        root = new trie('#');
    }
    
    void addWord(string word) {
        trie* t = root;
        for(int i = 0; i<word.size(); i++)
        {
            if(!t->child[word[i]-'a'])
                t->child[word[i]-'a'] = new trie(word[i]);
            if(i==word.size()-1)
                t->endHere = true;
            t = t->child[word[i]-'a'];
        }
    }
    
    bool searchTrie(trie* t, string word, int idx)
    {
        if(word[idx]=='.')
        {
            for(int i = 0; i<26; i++)
            {
                if(t->child[i])
                {
                    if(idx==word.size()-1)
                    {
                        if(t->endHere)
                            return true;
                        return false;
                    }
                    if(searchTrie(t->child[i], word, idx+1))
                        return true;
                }
            }
        }
        if(!t->child[word[idx]-'a'])
            return false;
        if(idx==word.size()-1)
        {
            if(t->endHere)
                return true;
            return false;
        }
        if(searchTrie(t->child[word[idx]-'a'], word, idx+1))
            return true;
        return false;
    }
    bool search(string word) {
        trie* t = root;
        return searchTrie(t, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
