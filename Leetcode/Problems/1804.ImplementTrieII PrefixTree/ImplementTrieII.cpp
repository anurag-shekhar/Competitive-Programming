/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : ImplementTrieII.cpp
 * Created on : Thu May 13 2021
 ****************************************************************
 */

class Trie {
public:
    class node
    {
        public:
        char ch;
        int endHere;
        int prefixCount;
        vector<node*> child;

        node(char a): ch(a), endHere(0), prefixCount(0), child(vector<node*> (26,NULL)){}

    };
    
    node* root;
    Trie() {
         root= new node('#');
    }
    
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
    
    int countWordsEqualTo(string word) {
        node* ptr = root;
        int n = word.size();
        for(int i = 0; i<n; i++)
        {
            int childValue = word[i]-'a';
            if(!ptr->child[childValue])
                return 0;
            if(i==n-1)
            {
                return ptr->child[childValue]->endHere;
            }
            ptr = ptr->child[childValue];
        }
        return 0;
    }
    
    int countWordsStartingWith(string prefix) {
        node* ptr = root;
        int n = prefix.size();
        for(int i = 0; i<n; i++)
        {
            int childValue = prefix[i]-'a';
            if(!ptr->child[childValue])
                return false;
            int count = ptr->child[childValue]->prefixCount;
            if( count < 1)
                return 0;
            if(i==n-1)
                return count;
            ptr = ptr->child[childValue];
        }
        return 0;
    }
    
    void erase(string word) {
        node* ptr = root;
        int n = word.size();
        for(int i = 0; i<n; i++)
        {
            int childValue = word[i]-'a';
            if(!ptr->child[childValue])
                return;
            if(ptr->child[childValue]->prefixCount)
                ptr->child[childValue]->prefixCount--;
            if(i==n-1)
            {
                if(ptr->child[childValue]->endHere)
                    ptr->child[childValue]->endHere--;
            }
            ptr = ptr->child[childValue];
        }
        return;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
