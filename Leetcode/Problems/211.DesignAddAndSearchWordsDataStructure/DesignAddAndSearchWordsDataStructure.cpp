/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : DesignAddAndSearchWordsDataStructure.cpp
 * Created on : Mon Jun 14 2021
 ****************************************************************
 */


class WordDictionary {
public:
    /** Initialize your data structure here. */
   
    unordered_map<int, vector<string> > m;
    
    bool isEqual(string a, string b)
    {
        int n = b.size();
        int i;
        for(i = 0; i<n; i++)
        {
            if(b[i]!='.' && a[i] != b[i])
                return false;
        }
        if(i==n)
            return true;
        return false;
    }
    WordDictionary() {
        m.clear();
    }
    
    void addWord(string word) {
        m[word.size()].push_back(word);
    }
    
 
    bool search(string word) {
        
        for(string s : m[word.size()])
            if(isEqual(s,word))
                return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
