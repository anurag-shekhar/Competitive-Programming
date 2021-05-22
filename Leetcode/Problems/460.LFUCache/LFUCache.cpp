/*
 ****************************************************************
 * Author : Anurag Shekhar
 * Email : anurag.shekhar.work@gmail.com
 *
 * Github : https://github.com/anurag-shekhar
 * LinkedIn : https://www.linkedin.com/in/anurag-shekhar/
 *
 * File Name : LFUCache.cpp
 * Created on : Sun May 23 2021
 ****************************************************************
 */

class LFUCache {
public:
    class LL
    {
        public:
        int key;
        int val;
        LL* next;
        LL* prev;
        LL(int k, int v):key(k), val(v), next(NULL), prev(NULL){}
    };
    unordered_map<int, pair<int, LL*> > key_freq;
    unordered_map<int, pair<LL*, LL*> > freq_list;
    int currSize, size, min_freq;
    
    void remove(LL* node, int freq, int key)
    {
        currSize--;
        key_freq.erase(key);
        
        LL* head = freq_list[freq].first;
        LL* tail = freq_list[freq].second;
        
        LL* p = node->prev;
        LL* n = node->next;
        
        node->next = NULL;
        node->prev = NULL;
        
        if(p)
            p->next = n;
        if(n)
            n->prev = p;
        
        if(node == tail)
            tail = p;
        if(node==head)
            head = n;
        
        if(!head)
            freq_list.erase(freq);
        else 
            freq_list[freq] = make_pair(head, tail);
        
        if(freq_list.count(min_freq)==0)
            min_freq++;
    }
    void insert(LL* node, int freq,int key)
    {
        currSize++;
        
        key_freq[key] = make_pair(freq,node);
        
        LL* head = NULL, *tail=NULL;
        if(freq_list.count(freq))
        {
            head = freq_list[freq].first;
            tail = freq_list[freq].second;
            
        }
        
        if(head)
        {
            node->next = head;
            head->prev = node; 
            head = node;
        }
        else 
        {
            head = node;
            tail = node;
        }
        freq_list[freq] = make_pair(head, tail);
    }
    LFUCache(int capacity) {
        size = capacity;
        currSize = 0;
        key_freq.clear();
        freq_list.clear();
        min_freq = 0;
    }
    
    int get(int key) {
        if(key_freq.count(key)==0 || size == 0)
            return -1;
        pair<int, LL*> p  = key_freq[key];
        int value = p.second->val;
        put(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if(size ==0)
            return;
        LL* node;
        int freq;
        if(key_freq.count(key)==0)
        {
            if(currSize >= size)
            {
                LL* tail = freq_list[min_freq].second;
                remove(tail, min_freq, tail->key);
            }
            node = new LL(key,value);
            freq = 1;
            min_freq = 1;
        }
        else 
        {
            key_freq[key].second->val = value;
            pair<int, LL*> p = key_freq[key];
            node = p.second;
            freq = p.first;
            remove(node, freq, key);
            freq++;
        }
        insert(node, freq, key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
