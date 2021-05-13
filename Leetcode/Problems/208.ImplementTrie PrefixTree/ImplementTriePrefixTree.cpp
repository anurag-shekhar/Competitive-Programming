/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ImplementTriePrefixTree.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

class Trie {
public:
    /** Initialize your data structure here. */
    class node
    {
        public:
        char ch;
        int endHere;
        int prefixCount;
        vector<node*> child;
        
        node(char a): ch(a), endHere(0), prefixCount(0), child(vector<node*> (26,NULL)){}
        
    };
    node *root;
    Trie() {
        root= new node('#');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        node* ptr = root;
        int n = word.size();
        for(int i = 0; i<n; i++)
        {
            int childValue = word[i]-'a';
            if(!ptr->child[childValue])
                ptr->child[childValue] = new node(word[i]);

            if(i==n-1)
                ptr->child[childValue]->endHere++;
            ptr->child[childValue]->prefixCount++;
            
            ptr = ptr->child[childValue];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* ptr = root;
        int n = word.size();
        for(int i = 0; i<n; i++)
        {
            int childValue = word[i]-'a';
            if(!ptr->child[childValue])    
                return false;
            if(i==n-1)
            {
                if(ptr->child[childValue]->endHere >= 1)
                    return true;
                else 
                    return false;
            }
            ptr = ptr->child[childValue];
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* ptr = root;
        int n = prefix.size();
        for(int i = 0; i<n; i++)
        {
            int childValue = prefix[i]-'a';
            if(!ptr->child[childValue])    
                return false;
            if(ptr->child[childValue]->prefixCount < 1)
                return false;
            if(i==n-1)
                return true;
            ptr = ptr->child[childValue];
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
